// BT Creation & displaying using all 4 traversals [ITERATIVE APPROACH]
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
    void Levelorder(Node *p);
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

// Preorder function
void Tree::Preorder(Node *p)
{
    stack<Node *> st(15);
    while (p || !st.IsEmpty())
    {
        if (p)
        {
            cout << p->data << " ";
            st.push(p);
            p = p->lchild;
        }
        else
        {
            p = st.pop();
            p = p->rchild;
        }
    }
}

// Inorder function
void Tree::Inorder(Node *p)
{
    stack<Node *> st(15);
    while (p || !st.IsEmpty())
    {
        if (p)
        {
            st.push(p);
            p = p->lchild;
        }
        else
        {
            p = st.pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}

// Postorder function
void Tree::Postorder(Node *p)
{
    long int temp;
    stack<long int> st(15);
    while (p || !st.IsEmpty())
    {
        if (p)
        {
            st.push((long int)p);
            p = p->lchild;
        }
        else
        {
            temp = st.pop();
            if (temp > 0)
            {
                st.push(-temp);
                p = ((Node *)temp)->rchild;
            }
            else
            {
                cout << ((Node *)(-1 * temp))->data << " ";
                p = NULL;
            }
        }
    }
}

// LevelOrder function
void Tree::Levelorder(Node *p)
{
    Queue q(20);
    cout << root->data << " ";
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        if (p->lchild)
        {
            cout << p->lchild->data << " ";
            q.enqueue(p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data << " ";
            q.enqueue(p->rchild);
        }
    }
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
    cout << "\nThe Levelorder is: "
         << "\n";
    t.Levelorder(t.root);

    return 0;
}
