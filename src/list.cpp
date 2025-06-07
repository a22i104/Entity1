//#include "list.h"
//
//template <typename T>
//List<T>::~List() {
//    Node* nowNode = top;
//    while (nowNode) {
//        Node* nextNode = nowNode->next;
//        delete nowNode;
//        nowNode = nextNode;
//    }
//    top = nullptr;
//    btm = nullptr;
//    size = 0;
//}
//
//template <typename T>
//void List<T>::push_back(const T& value) {
//    Node* newNode = new Node(value);
//    if (!btm) {
//        top = btm = newNode;
//    }
//    else {
//        btm->next = newNode;
//        newNode->prev = btm;
//        btm = newNode;
//    }
//    ++size;
//}
//
//template <typename T>
//void List<T>::push_front(const T& value) {
//    Node* newNode = new Node(value);
//    if (!top) {
//        top = btm = newNode;
//    }
//    else {
//        newNode->next = top;
//        top->prev = newNode;
//        top = newNode;
//    }
//    ++size;
//}
//
//template <typename T>
//void List<T>::pop_back() {
//    if (!btm) return;
//    Node* temp = btm;
//    if (top == btm) {
//        top = btm = nullptr;
//    }
//    else {
//        btm = btm->prev;
//        btm->next = nullptr;
//    }
//    delete temp;
//    --size;
//}
//
//template <typename T>
//void List<T>::pop_front() {
//    if (!top) return;
//    Node* temp = top;
//    if (top == btm) {
//        top = btm = nullptr;
//    }
//    else {
//        top = top->next;
//        top->prev = nullptr;
//    }
//    delete temp;
//    --size;
//}
//
//template <typename T>
//void List<T>::node_print() const {
//    Node* current = top;
//    while (current) {
//        std::cout << current->data << " ";
//        current = current->next;
//    }
//    std::cout << std::endl;
//}
//
//// 明示的インスタンス化（.cppを分けた場合必要）
//template class List<int>;
//template class List<std::string>;
