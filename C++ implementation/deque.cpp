#include <stdexcept>
#include <cstddef>


template<typename T>
struct Node{
    T val;
    Node* next;
    Node* prev;

    Node(const T& value): val(value), next(nullptr), prev(nullptr) {}
    Node(const T& value, Node* next): val(value), next(next), prev(nullptr) {}
    Node(const T& value, Node* next, Node* prev): val(value), next(next), prev(prev) {} 
};

template<typename T>
class Deque {
   private:
    std::size_t size;
    Node<T>* head;
    Node<T>* tail;

   public:
    Deque(): head(nullptr), tail(nullptr), size(0) {}

    ~Deque() {
        while(size > 0) pop_front();
    }

    void push_front(const T& value) {
        Node<T>* newNode = new Node(value);

        if(size == 0) {
            head = tail = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void push_back(const T& value) {cd
        Node<T>* newNode = new Node(value);

        if(size == 0) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void pop_front() {
        if(size == 0) throw std::runtime_error("deque is empty");

        Node<T>* temp = head;
        head = head->next;

        if(head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;   
        size--;
    }

    void pop_back() {
        if (size == 0)
            throw std::runtime_error("deque is empty");

        Node<T>* temp = tail;
        tail = tail->prev;

        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;

        delete temp;
        --size;
    }

    T& front() {
        return head->val;
    }

    T& back() {
        return tail->val;
    }

    void clear() {
        while(size > 0) pop_front();
    }
};