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
    ~List() { /* ���ׂč폜����R�[�h���K�v */ }
    
    void push_back(const T& x) {
        
    }
    void push_front() {

    }
    void pop_back() {

    }
    void pop_front() {

    }



    //�e���v��7�y�[�W�ڂ̑��������A���X�g�����̒ǉ��A�����A�擪�̒ǉ��A�擪�̏����@�v�b�V���o�b�N�A�v�b�V���t�����g�A�|�b�v�o�b�O�A�|�b�v�t�����g