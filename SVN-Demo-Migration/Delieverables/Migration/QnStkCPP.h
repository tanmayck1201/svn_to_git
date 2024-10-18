#include <iostream>
#include <stdio.h>
using namespace std;

// DLL creation for Binary Tree
class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
    Node(){};
    Node(int data);
};

Node::Node(int data)
{
    lchild = nullptr;
    this->data = data;
    rchild = nullptr;
}

// Queue implementation for BT creation & Level order traversal
class Queue
{
private:
    int front;
    int rear;
    int size;
    Node **Q;

public:
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new Node *[size];
    }
    // Destructor.
    /*Queue::~Queue()
    {
        delete[] Q;
    }*/
    void enqueue(Node *x);
    Node *dequeue();
    int isEmpty() { return front == rear; }
};

void Queue::enqueue(Node *x)
{
    if (rear == size - 1)
        ;
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node *Queue::dequeue()
{
    Node *x = NULL;
    if (front == rear)
        ;
    else
    {

        x = Q[front + 1];
        front++;
    }
    return x;
}

// Stack implementation using Template class.
template <class T>
class stack
{
private:
    int size;
    int top;
    T *s;

public:
    stack(int size);
    void push(T x);
    T pop();
    T stacktop();
    int IsEmpty()
    {
        if (top == -1)
            return 1;
        return 0;
    }
};

template <class T>
stack<T>::stack(int size)
{
    top = -1;
    this->size = size;
    s = new T[size];
}

template <class T>
void stack<T>::push(T x)
{
    if (top == size - 1)
    {
        ;
    }
    else
    {
        top++;
        s[top] = x;
    }
}

template <class T>
T stack<T>::pop()
{
    T x = 0;
    if (top == -1)
    {
        ;
    }
    else
    {
        x = s[top];
        top--;
    }
    return x;
}

template <class T>
T stack<T>::stacktop()
{
    T x = 0;
    if (top == -1)
    {
        ;
    }
    else
    {
        x = s[top];
    }
    return x;
}