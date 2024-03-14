/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>

struct Node {
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val) : prev(p), next(n), key(k), value(val) {};
    Node(int k, int val) : prev(nullptr), next(nullptr), key(k), value(val) {};
};

class Cache {
protected:
    std::map<int, Node*> mp; // map the key to the node in the linked list
    int cp;  // capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; // set function
    virtual int get(int) = 0; // get function
};

class LRUCache : public Cache {
public:
    LRUCache(int capacity) {
        cp = capacity;
        head = nullptr;
        tail = nullptr;
    }

    void set(int key, int value) override {
        if (mp.find(key) != mp.end()) { // key already exists
            mp[key]->value = value; // update the value
            update(mp[key]); // move the node to the front
            return;
        }

        Node* newNode = new Node(key, value);
        if (mp.size() >= cp) { // cache is full
            mp.erase(tail->key); // remove the least recently used node from the map
            remove(tail); // remove it from the linked list
        }

        mp[key] = newNode;
        add(newNode);
    }

    int get(int key) override {
        if (mp.find(key) != mp.end()) {
            update(mp[key]); // move the accessed node to the front
            return mp[key]->value;
        }
        return -1; // key not found
    }

private:
    void update(Node* node) {
        // remove the node from the list
        if (node->prev != nullptr) {
            node->prev->next = node->next;
        } else {
            head = node->next;
        }
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev;
        }
        // add the node to the front
        add(node);
    }

    void add(Node* node) {
        node->next = head;
        node->prev = nullptr;
        if (head != nullptr) {
            head->prev = node;
        }
        head = node;
        if (tail == nullptr) {
            tail = node;
        }
    }

    void remove(Node* node) {
        if (node->prev != nullptr) {
            node->prev->next = node->next;
        } else {
            head = node->next;
        }
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev;
        }
        delete node;
    }
};

int main() {
    int n, capacity, i;
    std::cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++) {
        std::string command;
        std::cin >> command;
        if (command == "get") {
            int key;
            std::cin >> key;
            std::cout << l.get(key) << std::endl;
        } else if (command == "set") {
            int key, value;
            std::cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
} // end of main
