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
    Node *RSearchBST(Node *p, int key);
    Node *RInsertBST(Node *p, int key);
    Node *RDeleteBST(Node *p, int key);
    Node *InPre(Node *p);
    Node *InSucc(Node *p);
    int Height(Node *p);
    void Inorder(Node *p);
    void CleanUp(Node *p);
};

BST::BST()
{
    root = nullptr;
}

// Acts as destructor for tree
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

// To search key present or not in tree
Node *BST::RSearchBST(Node *p, int key)
{
    if (p == nullptr)
    {
        return nullptr;
    }

    if (key == p->data)
    {
        return p;
    }
    else if (key < p->data)
    {
        return RSearchBST(p->lchild, key);
    }
    else
    {
        return RSearchBST(p->rchild, key);
    }
}

Node *BST::RInsertBST(Node *p, int key)
{
    Node *t;
    // To create new node while inserting new key everytime!
    if (p == nullptr)
    {
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        return t;
    }

    // Decide to insert left or right of node
    if (key < p->data)
    {
        p->lchild = RInsertBST(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = RInsertBST(p->rchild, key);
    }
    return p; // key == p->data
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

// find inorder predecessor of node
Node *BST::InPre(Node *p)
{
    // For successor get rightmost child node of left subtree from the given node
    while (p && p->rchild != nullptr)
    {
        p = p->rchild;
    }
    return p;
}

// find inorder successor of node
Node *BST::InSucc(Node *p)
{
    // For successor get leftmost child node of right subtree from the given node
    while (p && p->lchild != nullptr)
    {
        p = p->lchild;
    }
    return p;
}

// Height of tree
int BST::Height(Node *p)
{
    int x;
    int y;
    if (p == nullptr)
    {
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

// Delete nodes of tree (incl. all cases)
Node *BST::RDeleteBST(Node *p, int key)
{
    Node *q;
    // If tree is empty!
    if (p == nullptr)
    {
        return nullptr;
    }
    // If it's leaf node
    if (p->lchild == nullptr && p->rchild == nullptr && key == p->data)
    {
        // if leaf node is root itself then needed!
        if (p == root)
        {
            root = nullptr;
        }
        delete p;
        return nullptr;
    }
    // Decide where to traverse for deletion in a tree
    if (key < p->data)
    {
        p->lchild = RDeleteBST(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = RDeleteBST(p->rchild, key);
    }
    // if node have one or two childs or more heirarchy furthure of that node we want to delete!
    else
    {
        // where ht is more get xcessor from that subtree [x= pred or succ]
        if (Height(p->lchild) > Height(p->rchild))
        {
            // for predecessor
            q = InPre(p->lchild);
            // shift predecessor node data to the one which we want to delete actually.
            p->data = q->data;
            // delete the node of which predecessor is taken! [physically this node will be deleted!]
            p->lchild = RDeleteBST(p->lchild, q->data);
        }
        else
        {
            // for successor
            q = InSucc(p->rchild);
            // shift successor node data to the one which we want to delete actually.
            p->data = q->data;
            // delete the node from which successor data is taken! [physically this node will be deleted!]
            p->rchild = RDeleteBST(p->rchild, q->data);
        }
    }
    // deleted element inplce [needs to resolve still!]
    cout << "The modified element inplace of deleted element " << key << " is: " << p->data << endl;
    return p;
}

int main()
{
    BST b;
    int n, m;
    cout << "Enter no. of elements u want to enter: ";
    cin >> n;

    cout << "Enter the elements: ";
    cin >> m;
    b.root = b.RInsertBST(b.root, m);
    for (int i = 1; i < n; i++)
    {
        cin >> m;
        b.RInsertBST(b.root, m);
    }

    cout << "The Inorder Traversal is: ";
    b.Inorder(b.root);

    cout << "\nSearch for any element: ";
    cin >> m;
    if (b.RSearchBST(b.root, m))
    {
        cout << "Element is found!!" << endl;
    }
    else
    {
        cout << "Element not found!!" << endl;
    }

    b.RDeleteBST(b.root, m);
    b.Inorder(b.root);

    // acts as a destructor for tree!
    cout << endl;
    b.CleanUp(b.root);

    return 0;
}