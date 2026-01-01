template<typename T>
struct Node {
    T value;
    Node* next;
    Node* prev;

    Node(const T& val): value(val), prev(nullptr), next(nullptr) {}
};

template<typename T>
class Stack {
   private:
    Node<T>* tail;
    std::size_t size;

    Stack(): size(0), tail(nullptr) {};
    
    ~Stack() {
        while(size > 0) {
            pop();
        }
    }

    void pop() {
        if(!tail) return;

        Node<T>* temp = tail;
        tail = tail->prev;
        delete temp;

        --size;
    }

    void push(const T& value) {
        if(!tail) {
            tail = new Node(value);
        } else {
            Node<T>* temp = tail;
            tail = new Node(value);
            temp->next = tail;
            tail->prev = temp;
        }
        ++size;
    }

    T top() {
        if(!tail) return;
        return tail->value;
    }
};