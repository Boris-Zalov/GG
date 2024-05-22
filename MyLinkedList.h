#pragma once

#include <initializer_list>
#include <random>
#include <iostream>

#include "ComparableConcept.hpp"

template <Comparable T>
class MyLinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *head = nullptr;
    Node *tail = nullptr;

public:
    // Klase, kas ļauj iterēt caur sarakstu (piemēram, izmantojot range-based for ciklu)
    class Iterator
    {
    private:
        Node *current;

    public:
        explicit Iterator(Node *node) : current(node) {}

        T &operator*() const
        {
            return current->data;
        }

        Iterator &operator++()
        {
            current = current->next;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const Iterator &other) const
        {
            return current == other.current;
        }

        bool operator!=(const Iterator &other) const
        {
            return current != other.current;
        }
    };

    Iterator begin()
    {
        return Iterator(head);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }

    MyLinkedList(std::initializer_list<T> values)
    {
        for (const T &value : values)
        {
            push_back(value);
        }
    }

    MyLinkedList() {}

    ~MyLinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    void push_back(const T &value)
    {
        Node *newNode;
        try
        {
            newNode = new Node{value, nullptr};
        }
        catch (std::bad_alloc &e)
        {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            return;
        }

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void push_front(const T &value)
    {
        Node *newNode;
        try
        {
            newNode = new Node{value, nullptr};
        }
        catch (std::bad_alloc &e)
        {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            return;
        }

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    // Atgriež iteratoru uz nākamo elementu pēc dzēšanas
    Iterator erase(Iterator to_delete)
    {
        Node *current = head;
        Node *prev = nullptr;

        for (auto it = begin(); current != nullptr; ++it)
        {
            if (it == to_delete)
            {
                if (prev == nullptr)
                {
                    head = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                if (current == tail)
                {
                    tail = prev;
                }
                delete current;
                return ++it;
            }
            prev = current;
            current = current->next;
        }
        throw std::runtime_error("Element not found, even though it should be there");
    }

    void print()
    {
        for (Comparable auto elem : *this)
        {
            std::cout << elem << " -> ";
        }
        std::cout << "nullptr" << std::endl;
    }

    // Pateicoties statiskai analīzei, kompilators zina, ka šis koncepts ir izpildīts, tāpēc var izsaukt šo funkciju.
    void fill_random_numbers(unsigned int n, int min, int max)
    {
        if (min > max)
            throw std::invalid_argument("Cannot generate random numbers with min > max");

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<T> dis(min, max);
        for (unsigned int i = 0; i < n; ++i)
        {
            push_front(dis(gen));
        }
    }

    unsigned int size()
    {
        unsigned int size = 0;
        for (auto it = begin(); it != end(); ++it)
        {
            ++size;
        }
        return size;
    }
};