// Q3: Insertion Sort for Linked List

#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertSorted(Node*& head, Node* newNode) {
    if (head == nullptr || newNode->data < head->data) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void insertionSort(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return; // Already sorted or empty list
    }

    Node* sorted = nullptr; // Initialize sorted list

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        insertSorted(sorted, temp);
    }

    head = sorted; // Update head to point to sorted list
}

void displayList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = new Node(3);
    head->next = new Node(1);
    head->next->next = new Node(4);
    head->next->next->next = new Node(2);

    std::cout << "Original list: ";
    displayList(head);

    insertionSort(head);

    std::cout << "Sorted list: ";
    displayList(head);

    return 0;
}
