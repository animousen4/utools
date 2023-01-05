#pragma once
#include <iostream>

template <typename T>
class CustomList {
private:
    // Node class for storing data and pointers to the next and previous nodes
    class Node {
    public:
        T data;
        Node* next;
        Node* prev;

        // Constructor to initialize data and pointers
        Node(const T& data, Node* next = nullptr, Node* prev = nullptr)
            : data(data), next(next), prev(prev) {}
    };

    // Pointer to the head (first) and tail (last) nodes of the list
    Node* head;
    Node* tail;

    // Size of the list
    size_t size_;

public:
    // Default constructor
    CustomList() : head(nullptr), tail(nullptr), size_(0) {}

    // Destructor to free memory
    ~CustomList() {
        clear();
    }

    // Copy constructor
    CustomList(const CustomList& other) {
        head = tail = nullptr;
        size_ = 0;
        for (Node* node = other.head; node; node = node->next) {
            push_back(node->data);
        }
    }

    // Move constructor
    CustomList(CustomList&& other) : head(other.head), tail(other.tail), size_(other.size_) {
        other.head = other.tail = nullptr;
        other.size_ = 0;
    }

    // Copy assignment operator
    CustomList& operator=(const CustomList& other) {
        if (this != &other) {
            clear();
            for (Node* node = other.head; node; node = node->next) {
                push_back(node->data);
            }
        }
        return *this;
    }

    // Move assignment operator
    CustomList& operator=(CustomList&& other) {
        if (this != &other) {
            clear();
            head = other.head;
            tail = other.tail;
            size_ = other.size_;
            other.head = other.tail = nullptr;
            other.size_ = 0;
        }
        return *this;
    }

    // Check whether the list is empty
    bool empty() const {
        return !head;
    }

    // Return the size of the list
    size_t size() const {
        return size_;
    }

    // Add an element to the front of the list
    void push_front(const T& data) {
        Node* node = new Node(data, head);
        if (head) {
            head->prev = node;
        }
        head = node;
        if (!tail) {
            tail = node;
        }
        ++size_;
    }

    // Add an element to the back of the list
    void push_back(const T& data) {
        Node* node = new Node(data, nullptr, tail);
        if (tail) {
            tail->next = node;
        }
        tail = node;
        if (!head) {
            head = node;
        }
        ++size_;
    }

    // Remove an element from the front of the list
    void pop_front() {
        if (!head) {
            return;
        }
        Node* old_head = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        delete old_head;
        --size_;
    }

    // Remove an element from the back of the list
    void pop_back() {
        if (!tail) {
            return;
        }
        Node* old_tail = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        }
        delete old_tail;
        --size_;
    }

    // Clear the list (delete all elements and reset size to 0)
    void clear() {
        Node* node = head;
        while (node) {
            Node* next = node->next;
            delete node;
            node = next;
        }
        head = tail = nullptr;
        size_ = 0;
    }

    // Return the element at the front of the list
    T& front() {
        return head->data;
    }

    // Return the element at the back of the list
    T& back() {
        return tail->data;
    }

    // Const version of front()
    const T& front() const {
        return head->data;
    }

    // Const version of back()
    const T& back() const {
        return tail->data;
    }

    T& operator[](size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        Node* node = head;
        for (size_t i = 0; i < index; ++i) {
            node = node->next;
        }
        return node->data;
    }
};

