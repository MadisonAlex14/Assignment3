// Q1: Implement Queue Data Structure 

#include <iostream>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;
    int size;

public:
    Queue() : frontNode(nullptr), rearNode(nullptr), size(0) {}

    void push(T val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        }
        else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        size++;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot pop.\n";
            return;
        }
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        size--;
    }

    T front() {
        if (isEmpty()) {
            std::cout << "Queue is empty. No front element.\n";
            return T();
        }
        return frontNode->data;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void move_to_rear() {
        if (isEmpty() || size == 1) {
            std::cout << "Queue is empty or contains only one element. Cannot move.\n";
            return;
        }
        push(front());
        pop();
    }
};

int main() {
    Queue<int> myQueue;
    for (int i = 1; i <= 10; i++) {
        myQueue.push(i * 10);
    }

    std::cout << "Queue elements: ";
    while (!myQueue.isEmpty()) {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }
    std::cout << std::endl;

    return 0;
}
