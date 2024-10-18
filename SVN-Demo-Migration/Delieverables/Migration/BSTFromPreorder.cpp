// Pgm for Creating BST from Preorder!
#include <iostream>
#include "QnStkCPP.h"
using namespace std;

class BST
{
private:
public:
    Node *root;
    BST();
    void PreCreateTree(int p[], int n);
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

void BST::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

void BST::PreCreateTree(int pre[], int n)
{
    stack<Node *> stk(10);
    int i = 0;
    Node *t = 0;
    Node *p = 0;
    root = new Node(pre[i++]);
    p = root;

    while (i < n)
    {
        if (pre[i] < p->data)
        {
            t = new Node(pre[i++]);
            p->lchild = t;
            stk.push(p);
            p = t;
        }
        else
        {
            if (pre[i] > p->data && pre[i] < (stk.IsEmpty() ? 32767 : stk.stacktop()->data))
            {
                t = new Node(pre[i++]);
                p->rchild = t;
                p = t;
            }
            else
            {
                p = stk.pop();
            }
        }
    }
}

int main()
{
    BST b;
    int n, *pre;
    cout << "Enter no. of elements u want to enter: ";
    cin >> n;
    pre = new int[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    b.PreCreateTree(pre, n);

    cout << "The Inorder Traversal is: ";
    b.Inorder(b.root);

    // acts as a destructor for tree!
    cout << endl;
    b.CleanUp(b.root);

    return 0;
}