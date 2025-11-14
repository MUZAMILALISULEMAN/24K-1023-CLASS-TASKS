#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


class AVLTreeNode {
public:
    int key;
    int height;
    AVLTreeNode* left;
    AVLTreeNode* right;

    
    AVLTreeNode(int k) {
        key = k;
        height = 1;  
        left = right = nullptr;
    }
};


int height(AVLTreeNode* node) {
    return node ? node->height : 0;
}

int balanceFactor(AVLTreeNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}


AVLTreeNode* rightRotate(AVLTreeNode* y) {
    AVLTreeNode* x = y->left;
    AVLTreeNode* t = x->right;

   
    x->right = y;
    y->left = t;

    
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}


AVLTreeNode* leftRotate(AVLTreeNode* x) {
    AVLTreeNode* y = x->right;
    AVLTreeNode* t = y->left;

    
    y->left = x;
    x->right = t;


    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}


AVLTreeNode* insertNode(AVLTreeNode* node, int key) {
   
    if (!node) return new AVLTreeNode(key);

    if (key < node->key) {
        node->left = insertNode(node->left, key);
    } else if (key > node->key) {
        node->right = insertNode(node->right, key);
    } else {
        return node; 
    }

 
    node->height = max(height(node->left), height(node->right)) + 1;


    int balance = balanceFactor(node);




    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }


    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }


    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

  
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;  
}


void preorder(AVLTreeNode* root) {
    if (!root) return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}


void levelOrder(AVLTreeNode* root) {
    if (!root) return;

    queue<AVLTreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        AVLTreeNode* current = q.front();
        q.pop();
        cout << current->key << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << endl;
}

int main() {
    AVLTreeNode* root = nullptr;

    cout << "Enter the roll numbers of students to insert into the AVL tree:" << endl;

   
    vector<int> studentRollNumbers = {10, 20, 30, 40, 50, 15}; 
    for (int rollNumber : studentRollNumbers) {
        root = insertNode(root, rollNumber);
    }


    cout << "Pre-order traversal of the AVL tree:" << endl;
    preorder(root);
    cout << endl;

    cout << "Level-order traversal:" << endl;
    levelOrder(root);

    return 0;
}
