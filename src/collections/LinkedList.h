//
// Created by Oleksandra Baukh on 1/19/18.
//

#ifndef CPP_PLAYGROUND_LINKEDLIST_H
#define CPP_PLAYGROUND_LINKEDLIST_H

#include "List.h"

template<class T>
class LinkedList : public List<T> {
    struct Node {
        T *data;
        Node *prev, *next;

        Node(T *obj) : data(obj), prev(nullptr), next(nullptr) {}
    };

    Node *left = nullptr, *right = nullptr;
    int length = 0;

    void removeNode(Node *node) {
        if (node == nullptr) {
            return;
        }

        if (node == right) {
            right = nullptr;
        }

        if (node == left) {
            left = node->next;
        } else {
            Node *previous = node->prev;
            Node *next = node->next;
            if (previous != nullptr) {
                previous->next = next;
            }
            if (next != nullptr) {
                next->prev = previous;
            }

            if (previous == nullptr && next == nullptr) {
                left = nullptr;
                right = nullptr;
            }
        }
        delete node;
        length--;
    }

    Node *findNode(int index) {
        if (index >= length) {
            return nullptr;
        }

        int startIndex = 0;
        Node *currentNode = left;
        while (startIndex != index) {
            currentNode = currentNode->next;
            startIndex++;
        }
        return currentNode;
    }

public:
    bool removeByPointer(T *e) override {
        bool deleted = false;
        auto pointer = iterator();
        Iterator<T> *it = pointer.get();
        while (it->hasNext()) {
            if (it->next() == e) {
                it->remove();
                deleted = true;
            }
        }
        return deleted;
    }

    void add(T *e) override {

        auto *node = new Node(e);

        if (right != nullptr) {
            right->next = node;
            node->prev = right;
            right = node;
        }

        if (left == nullptr) {
            left = node;
            right = node;
        }

        length++;
    }

    bool contains(T *e) override {
        auto pointerToIterator = iterator();
        auto iterator = pointerToIterator.get();
        while (iterator->hasNext()) {
            if (iterator->next() == e) {
                return true;
            }
        }
        return false;
    }

    int size() override {
        return length;
    }


    T *get(int index) override {
        Node *pNode = findNode(index);
        if (pNode == nullptr) {
            return nullptr;
        }
        return pNode->data;
    }

    Pointer<Iterator<T>> iterator() override {
        return {new LinkedListIterator(*this)};
    }

    T *remove(int index) override {
        Node *node = findNode(index);
        T *data = node->data;
        removeNode(node);
        return data;
    }

    class LinkedListIterator : public Iterator<T> {
        Node *currentNode;
        Node *nextNode;
        LinkedList &list;

    public:
        explicit LinkedListIterator(LinkedList &pList) : currentNode(pList.left), nextNode(pList.left), list(pList) {
        }

        bool hasNext() override {
            return nextNode != nullptr;
        }

        T *next() override {
            currentNode = nextNode;
            if (nextNode != nullptr) {
                T *data = nextNode->data;
                nextNode = nextNode->next;
                return data;
            } else {
                return nullptr;
            }
        }

        T *remove() override {
            if (currentNode == nullptr) {
                return nullptr;
            }
            T *data = currentNode->data;
            nextNode = currentNode->next;
            list.removeNode(currentNode);
            return data;
        }
    };
};


#endif //CPP_PLAYGROUND_LINKEDLIST_H
