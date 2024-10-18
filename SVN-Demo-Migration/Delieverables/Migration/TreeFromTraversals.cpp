// Creation of BT from Pre/Post & Inorder Traversals.
#include <iostream>
#include "QnStkCPP.h"

using namespace std;

class Tree
{
public:
    void Preorder(Node *root);
    void Postorder(Node *root);
    void Inorder(Node *root);
    void Levelorder(Node *p);
    int SearchInorder(int inArray[], int inStart, int inEnd, int data);
    Node *GenerateTreeFromPreorder(int *inorder, int *preorder, int inStart, int inEnd);
    Node *GenerateTreeFromPostorder(int *inorder, int *postorder, int inStart, int inEnd);
};

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
    cout << p->data << " ";
    q.enqueue(p);

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

// Search element of pre/post in inorder array to split list.
int Tree::SearchInorder(int inArray[], int inStart, int inEnd, int data)
{
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inArray[i] == data)
        {
            // returns index of matched element.
            return i;
        }
    }
    return -1;
}

// Generating Tree from preorder traversals.
Node *Tree ::GenerateTreeFromPreorder(int *inorder, int *preorder, int inStart, int inEnd)
{
    // once only initialized!
    static int preIndex = 0;

    if (inStart > inEnd)
    {
        // returns NULL as no child/data now!
        return nullptr;
    }

    // Create node of preoder data moving L to R.
    Node *node = new Node(preorder[preIndex++]);

    // if only 1 element there within bound!
    if (inStart == inEnd)
    {
        return node;
    }

    // Get split index to partition tree.
    int splitIndex = SearchInorder(inorder, inStart, inEnd, node->data);
    node->lchild = GenerateTreeFromPreorder(inorder, preorder, inStart, splitIndex - 1);
    node->rchild = GenerateTreeFromPreorder(inorder, preorder, splitIndex + 1, inEnd);

    // return the root node at last.
    return node;
}

// Generating Tree from postorder traversals.
Node *Tree ::GenerateTreeFromPostorder(int *inorder, int *postorder, int inStart, int inEnd)
{
    // once only initialized!
    static int postIndex = inEnd;

    if (inStart > inEnd)
    {
        // returns NULL as no child/data now!
        return nullptr;
    }
    // Create node of postoder data moving R to L.
    Node *node = new Node(postorder[postIndex--]);

    // if only 1 element there within bound!
    if (inStart == inEnd)
    {
        return node;
    }

    // Get split index to partition tree.
    int splitIndex = SearchInorder(inorder, inStart, inEnd, node->data);
    node->rchild = GenerateTreeFromPostorder(inorder, postorder, splitIndex + 1, inEnd);
    node->lchild = GenerateTreeFromPostorder(inorder, postorder, inStart, splitIndex - 1);

    // return the root node at last.
    return node;
}

// Main function
int main()
{
    Tree t;
    int *inorder, *preorder, *postorder, n;
    cout << "Enter size of i/p Pre/Post order & Inorder: ";
    cin >> n;

    inorder = new int[n];
    // preorder = new int[n];
    postorder = new int[n];

    // int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    // int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};

    /*cout << "Enter Preorder for tree: ";
    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }*/

    cout << "Enter Postorder for tree: ";
    for (int i = 0; i < n; i++)
    {
        cin >> postorder[i];
    }

    cout << "Enter Inorder for tree: ";
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }

    // Node *T = t.GenerateTreeFromPreorder(inorder, preorder, 0, n - 1);
    Node *T = t.GenerateTreeFromPostorder(inorder, postorder, 0, n - 1);

    cout << "\nThe Preorder is: "
         << "\n";
    t.Preorder(T);
    cout << "\nThe Inorder is: "
         << "\n";
    t.Inorder(T);
    cout << "\nThe Postorder is: "
         << "\n";
    t.Postorder(T);
    cout << "\nThe Levelorder is: "
         << "\n";
    t.Levelorder(T);

    return 0;
}
