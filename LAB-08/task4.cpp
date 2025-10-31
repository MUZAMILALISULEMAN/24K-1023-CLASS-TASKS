#include <iostream>
using namespace std;

class Node{
public:
    int data;
Node *left;
Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class BinaryTree{
public:
    Node *root;
    BinaryTree() : root(NULL) {}

    Node *newNode(int val)
    {
        return new Node(val);
    }

    int sum(Node *node)
    {
        if (!node)
            return 0;
        return node->data + sum(node->left) + sum(node->right);
    }

    bool find(Node *node, int target)
    {
        if (!node)
            return false;
        int total = sum(node);
        if (total == target)
        {
            cout << "Subtree with sum " << target << ": [";
            printSubtree(node);
            cout << "]" << endl;
            return true;
        }
        return find(node->left, target) || find(node->right, target);
    }

    void printSubtree(Node *node)
    {
        if (!node)
            return;
        cout << node->data;
        if (node->left || node->right)
            cout << ", ";
      
        printSubtree(node->left);
        if (node->left && node->right)
            cout << ", ";
        printSubtree(node->right);
      
    }
};

int main()
{
    BinaryTree t;
    t.root = t.newNode(5);
    t.root->left = t.newNode(6);
    t.root->right = t.newNode(8);
    t.root->left->left = t.newNode(1);
    t.root->left->right = t.newNode(2);
  
    t.root->right->left = t.newNode(76);
    t.root->right->right = t.newNode(10);

    int target;
    cout << "enter target sum: ";
    cin >> target;

    if (!t.find(t.root, target))
        cout << "No subtree found with sum " << target << "." << endl;
}
