// list.h

#pragma once
#include <functional>
#include <iostream>
#include <vector>

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
    void sort(const std::string& str);
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

template <typename T>
void List<T>::sort(const std::string& str) {
    auto Ascending = [](const T& a, const T& b) {
        return a > b;
        };
    auto Descending = [](const T& a, const T& b) {
        return a < b;
        };

    std::function<bool(const T&, const T&)> func;

    if (str == "up") {
        func = Ascending;
    }
    else if (str == "down") {
        func = Descending;
    }
 

    for (int i = 0; i < size; ++i) {
        Node* nowNode = top;
        for (int j = 0; j < size - 1 - i; ++j) {
            Node* nextNode = nowNode->next;
            if (func(nowNode->data, nextNode->data)) {
                std::swap(nowNode->data, nextNode->data);
            }
            nowNode = nextNode;
        }
    }
}
