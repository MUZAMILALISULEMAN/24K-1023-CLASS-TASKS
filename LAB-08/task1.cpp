#include <iostream>
#include <string>
using namespace std;

class TourPackage
{
public:
    string name;
    TourPackage *left;
    TourPackage *right;

    TourPackage(string n)
    {
        name = n;
        left = right = NULL;
    }
};

class TourTree
{
public:
    TourPackage *root;

    TourTree()
    {
        root = NULL;
    }

    void makeRoot(string n)
    {
        if (root == NULL)
            root = new TourPackage(n);
        else
            cout << "Root already exists.\n";
    }

    void add(TourPackage *node, string parent, string child, char side)
    {
        if (node == NULL)
            return;

        if (node->name == parent)
        {
            if (side == 'L')
            {
                if (node->left == NULL)
                    node->left = new TourPackage(child);
                else
                    cout << "Left child already exists.\n";
            }
            else if (side == 'R')
            {
                if (node->right == NULL)
                    node->right = new TourPackage(child);
                else
                    cout << "Right child already exists.\n";
            }
            return;
        }

        add(node->left, parent, child, side);
        add(node->right, parent, child, side);
    }

    void addNode(string parent, string child, char side)
    {
        if (root == NULL)
        {
            cout << "Create root first.\n";
            return;
        }
        add(root, parent, child, side);
    }

    // clean and raw output — preorder style
    void show(TourPackage *node)
    {
        if (node == NULL)
            return;
        cout << node->name << " ";
        show(node->left);
        show(node->right);
    }

    void display()
    {
        if (root == NULL)
            cout << "Tree is empty.\n";
        else
        {
            cout << "\nPackages (Preorder Traversal):\n";
            show(root);
            cout << endl;
        }
    }
};

int main()
{
    TourTree t;
    int ch;
    string name, parent;
    char side;

    cout << "==== TOUR PACKAGE TREE ====\n";

    while (true)
    {
        cout << "\n1. Create Root\n2. Add Package\n3. Display Tree\n4. Exit\nEnter choice: ";
        cin >> ch;
        cin.ignore();

        if (ch == 1)
        {
            cout << "Enter root name: ";
            getline(cin, name);
            t.makeRoot(name);
        }
        else if (ch == 2)
        {
            cout << "Enter parent name: ";
            getline(cin, parent);
            cout << "Enter child name: ";
            getline(cin, name);
            cout << "Enter side (L/R): ";
            cin >> side;
            cin.ignore();
            t.addNode(parent, name, side);
        }
        else if (ch == 3)
        {
            t.display();
        }
        else if (ch == 4)
        {
            cout << "Exiting program.\n";
            break;
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
