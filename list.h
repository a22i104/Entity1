#include <iostream>

template <typename T>
class List
{
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
    ~List() { /* すべて削除するコードが必要 */ }
    
    void push_back(const T& x) {
        
    }
    void push_front() {

    }
    void pop_back() {

    }
    void pop_front() {

    }



    //テンプレ7ページ目の続きを作る、リスト末尾の追加、消去、先頭の追加、先頭の消去　プッシュバック、プッシュフロント、ポップバッグ、ポップフロント