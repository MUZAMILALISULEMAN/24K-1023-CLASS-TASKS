#include <iostream>
using namespace std;

class Node
{
public:
    int id, qty;
    Node *left, *right;
    Node(int pid, int q)
    {
        id = pid;
        qty = q;
        left = right = NULL;
    }
};

class BST
{
public:
    Node *root;
    BST() { root = NULL; }

    Node *insert(Node *n, int id, int q)
    {
        if (!n)
            return new Node(id, q);
        if (id < n->id)
            n->left = insert(n->left, id, q);
        else if (id > n->id)
            n->right = insert(n->right, id, q);
        else
            n->qty += q;
        return n;
    }

    void add(int id, int q)
    {
        root = insert(root, id, q);
    }

    Node *search(Node *n, int id)
    {
        if (!n || n->id == id)
            return n;
        if (id < n->id)
            return search(n->left, id);
        return search(n->right, id);
    }

    Node *maxQty(Node *n, Node *m = NULL)
    {
        if (!n)
            return m;
        if (!m || n->qty > m->qty)
            m = n;
        m = maxQty(n->left, m);
        m = maxQty(n->right, m);
        return m;
    }

    void show(Node *n)
    {
        if (!n)
            return;
        show(n->left);
        cout << n->id << " " << n->qty << endl;
        show(n->right);
    }
};

int main()
{
    BST t;
    t.add(50, 20);
    t.add(30, 15);
    t.add(70, 25);
    t.add(20, 10);
    t.add(40, 12);
    t.add(60, 30);
    t.add(80, 18);
    t.add(60, 5);

    cout << "All Products:\n";
    t.show(t.root);

    int x = 40;
    Node *f = t.search(t.root, x);
    if (f)
        cout << "\nFound " << x << " " << f->qty << endl;
    else
        cout << "\nNot found\n";

    Node *m = t.maxQty(t.root);
    if (m)
        cout << "\nMax Qty: " << m->id << " " << m->qty << endl;

    return 0;
}
