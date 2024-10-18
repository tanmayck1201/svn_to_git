// Pgm for Creation, Search & Insertion of BST!
#include <iostream>
#include "QnStkCPP.h"
using namespace std;

class BST
{
private:
public:
    Node *root;
    BST();
    bool SearchBST(Node *p, int x);
    void InsertBST(int key);
    void Inorder(Node *p);
    void CleanUp(Node *p);
};

BST::BST()
{
    root = nullptr;
}

void BST::CleanUp(Node *p)
{
    if (p)
    {
        cout << "cleaning out : " << p->data << endl;
        Node *temp = p;
        CleanUp(p->lchild);
        CleanUp(p->rchild);
        delete temp;
    }
}

bool BST::SearchBST(Node *p, int x)
{
    while (p)
    {
        if (x == p->data)
        {
            return true;
        }
        else if (p->data < x)
        {
            p = p->rchild;
        }
        else
        {
            p = p->lchild;
        }
    }
    return false;
}

void BST::InsertBST(int key)
{
    Node *t = root;
    Node *p;
    Node *r;

    // root is empty
    if (root == nullptr)
    {
        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return;
    }

    while (t != nullptr)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        }
        else if (key > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return;
        }
    }

    // Now t points at NULL and r points at insert location
    p = new Node;
    p->data = key;
    p->lchild = nullptr;
    p->rchild = nullptr;

    if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

void BST::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

int main()
{
    BST b;
    int n, m;
    cout << "Enter no. of elements u want to enter: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        b.InsertBST(m);
    }

    cout << "The Inorder Traversal is: ";
    b.Inorder(b.root);

    cout << "\nSearch for any element: ";
    cin >> m;
    if (b.SearchBST(b.root, m))
    {
        cout << "Element is found!!" << endl;
    }
    else
    {
        cout << "Element not found!!" << endl;
    }

    // acts as a destructor for tree!
    b.CleanUp(b.root);

    return 0;
}