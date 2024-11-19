#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

template<typename T>

class Node
{
    // Your code here
    public:
    T value;
    Node<T>* down = nullptr;
    Node(T x){
        value = x;
    }
};

template<typename T>

class Stack
{
    // Your code here
    public:
    Node<T>* top;
    Stack()
    {
        top = nullptr;
    }

    Stack(T x){
        top = new Node(x);
    }

    bool isEmpty(){
        if (top == nullptr){
            return true;
        } else {
            return false;
        }
    }

    void push(T x){
        Node<T>* newNode = new Node(x);
        newNode->down = top;
        top = newNode;
    }

    T pop(){
        assert(top != nullptr);
        T val = top->value;
        Node<T>* newNode = top;
        top = top->down;
        delete(newNode);
        return val;
    }

    T peek(){
        assert(top != nullptr);
        return top->value;
    }
};