#include <cstddef>

template <typename T>
struct Node {
    T val;
    Node* next;
    
    Node(const T& val, Node* next = nullptr): val(val), next(next) {}
};

template <typename T>
class List {
private:
    Node<T>* head;
    std::size_t _size;

public:
    List(): head(nullptr), _size(0) {}

    ~List() {
        clear();
    }

    bool empty() const {
        return head == nullptr;
    }

    std::size_t size() const {
        return _size;
    }

    void push_front(const T& value) {
        head = new Node<T>(value, head);
        _size++;
    }

    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value, nullptr);

        if(!head) { 
            head = newNode;
        } else {
            Node<T>* curr = head;
            while(curr->next) curr = curr->next;
            curr->next = newNode;
        }
        ++_size;
    }

    void pop_front() {
        if(!head) return;

        Node<T>* temp = head;
        head = head->next;
        delete temp;
        _size--;
    }

    void pop_back() {
        if(!head) return;

        if(!head->next) {
            delete head;
            head = nullptr;
        } else {
            Node<T>* curr = head;
            while(curr->next->next) curr = curr->next;
            delete curr->next;
            curr->next = nullptr;
        }
        _size--;
    }

    bool remove(const T& target) {
        if(!head) return false;

        if(head->val == target) {
            pop_front();
            return true;   
        }

        Node<T>* curr = head;
        while(curr->next) {
            if(curr->next->val == target) {
                Node<T>* temp = curr->next;
                curr->next = temp->next;
                delete temp;
                _size--;
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    void clear() {
        while(head) pop_front();
    }
};

int main() {
    List<int> l;
    return 0;
}