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
        top = btm = newNode;
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
        top = btm = newNode;
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
    if (!btm) return;
    Node* temp = btm;
    if (top == btm) {
        top = btm = nullptr;
    }
    else {
        btm = btm->prev;
        btm->next = nullptr;
    }
    delete temp;
    --size;
}

template <typename T>
void List<T>::pop_front() {
    if (!top) return;
    Node* temp = top;
    if (top == btm) {
        top = btm = nullptr;
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

    //テンプレ7ページ目の続きを作る、リスト末尾の追加、消去、先頭の追加、先頭の消去　プッシュバック、プッシュフロント、ポップバッグ、ポップフロント