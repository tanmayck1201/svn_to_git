// Height & Count of a given tree!
#include <iostream>
#include "QnStkCPP.h"

using namespace std;

class Tree
{
public:
    Node *root;
    void CreateBT(Queue q);
    void Preorder(Node *root);
    void Postorder(Node *root);
    void Inorder(Node *root);
    int Count(Node *p);
    int Height(Node *p);
};

// Create Binary Tree.
void Tree ::CreateBT(Queue q)
{
    Node *p, *t = NULL;
    int x;
    cout << "Enter root value: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = 0;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter left child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = 0;
            p->lchild = t;
            q.enqueue(t);
        }

        cout << "Enter right child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = 0;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
}

int Tree::Count(Node *p)
{
    int x, y;
    if (p)
    {
        x = Count(p->lchild);
        y = Count(p->rchild);
        return x + y + 1;
    }
    return 0;
}

int Tree::Height(Node *p)
{
    int x, y;
    if (p)
    {
        x = Height(p->lchild);
        y = Height(p->rchild);
        if (x > y)
        {
            return x + 1;
        }
        else
        {
            return y + 1;
        }
    }
    return 0;
}

// Main function
int main()
{
    Queue q(25);
    Tree t;
    t.CreateBT(q);
    cout << "\nThe Preorder is: "
         << "\n";
    t.Preorder(t.root);
    cout << "\nThe Inorder is: "
         << "\n";
    t.Inorder(t.root);
    cout << "\nThe Postorder is: "
         << "\n";
    t.Postorder(t.root);

    cout << "\n\nThe count of nodes: " << t.Count(t.root) << endl;
    cout << "The Height of Tree is: " << t.Height(t.root) << endl;
    return 0;
}
