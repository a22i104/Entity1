// list.h

#pragma once
#include <iostream>

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* top;
    Node* btm;
    size_t size;

public:
    List() : top(nullptr), btm(nullptr), size(0) {}
    ~List();

    void push_back(const T& value);
    void push_front(const T& value);
    void pop_back();
    void pop_front();
    void node_print() const;
};


template <typename T>
List<T>::~List() {
    Node* nowNode = top;
    while (nowNode) {
        Node* nextNode = nowNode->next;
        delete nowNode;
        nowNode = nextNode;
    }
    top = nullptr;
    btm = nullptr;
    size = 0;
}

template <typename T>
void List<T>::push_back(const T& value) {
    Node* newNode = new Node(value);
    if (!btm) {
        btm = newNode;
        top = newNode;
    }
    else {
        btm->next = newNode;
        newNode->prev = btm;
        btm = newNode;
    }
    ++size;
}

template <typename T>
void List<T>::push_front(const T& value) {
    Node* newNode = new Node(value);
    if (!top) {
        btm =newNode;
        top =newNode;
    }
    else {
        newNode->next = top;
        top->prev = newNode;
        top = newNode;
    }
    ++size;
}

template <typename T>
void List<T>::pop_back() {
    Node* temp = btm;
    if(top==btm){
        top = nullptr;
        btm = nullptr;
    }
    else
    {
        btm = btm->prev;
        btm->next = nullptr;
    }
    delete temp;
    --size;
}

template <typename T>
void List<T>::pop_front() {

    Node* temp = top;
    if (top == btm) {
        btm = nullptr;
        top = nullptr;
    }
    else {
        top = top->next;
        top->prev = nullptr;
    }
    delete temp;
    --size;
}

template <typename T>
void List<T>::node_print() const {
    Node* nowNode = top;
    while (nowNode) {
        std::cout << nowNode->data << " ";
        nowNode = nowNode->next;
    }
    std::cout << std::endl;
}

void Ascending(int a,int b) {
    if(a>b)
    {
        int temp = b;
        b=a;
        a = temp;
    }
}//è∏èáevent1


void Descending(int a,int b){
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
}//ç~èáevent2

bool up = false;
bool down = false;

if()
int main()
{
    int i, j;
    
    for (int i = 0;i < size;i++)
    {
        for (j = size;j > i;j--)
        {
            if (up == true)
            {
                Ascending();
            }
            else if (down == true)
            {
                Descending();
            }

        }
    }




};