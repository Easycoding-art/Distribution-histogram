#pragma once
#define MY_CLASS_H
#include <iostream>
#include <string>
#include "Sequence.h"
#include "Person.h"
using namespace std;
template <typename A>
class tree_elem
{
public:
    A m_data;
    tree_elem* m_left;
    tree_elem* m_right;
    tree_elem(A val) {
        m_left = NULL; // В С++11 лучше использовать nullptr
        m_right = NULL;
        m_data = val;
    }
};
template <typename T> class binary_tree
{
private:
    tree_elem<T>* m_root = NULL;
    int m_size = 0;
    Sequence<T> print_tree(tree_elem<T>* curr, Sequence<T> vector) {
        if (curr) // Проверка на ненулевой указатель
        {
            vector = print_tree(curr->m_left, vector);
            vector = vector.add(curr->m_data);
            vector = print_tree(curr->m_right, vector);
        }
        return vector;
    }
    T* get_element_array(tree_elem<T>* curr, T* arr, int i) {
        if (curr) // Проверка на ненулевой указатель
        {
            arr = get_element_array(curr->m_left, arr, i + 1);
            arr[i] = (curr->m_data);
            arr = get_element_array(curr->m_right, arr, i + 1);
        }
        return arr;
    }
public:
    binary_tree() {}
    binary_tree(T key) {
        m_root = new tree_elem<T>(key);
        m_size = 1;
    }
    binary_tree(binary_tree<T>* tree) {
        T* arr = new T[tree->m_size];
        arr = get_element_array(tree->m_root, arr, 0);
        m_root = new tree_elem<T>(arr[0]);
        m_size = 1;
        for (int i = 1; i < tree->m_size; i++) {
            insert(arr[i]);
        }

        delete[] arr;
    };
    binary_tree(binary_tree* tree, bool (*func)(T)) {
        int i = 0;
        T* arr = new T[tree->m_size];
        arr = get_element_array(tree->m_root, arr, 0);
        while (func(arr[i]) != true) {
            if (func(arr[i]) == true) {
                insert(arr[i]);
            }
            i++;
        }
        m_root = new tree_elem<T>(arr[i]);
        m_size = 1;
        for (int j = 0; j < tree->m_size; j++) {
            if (func(arr[j]) == true && j != i) {
                insert(arr[j]);
            }
        }
        delete[] arr;
    }
    bool find(int key) {
        tree_elem<T>* curr = m_root;
        while (curr && curr->m_data != key)
        {
            if (curr->m_data > key)
                curr = curr->m_left;
            else
                curr = curr->m_right;
        }
        return curr != NULL;
    }
    void insert(T key) {
        tree_elem<T>* curr = m_root;
        while (curr && curr->m_data != key)
        {
            if (curr->m_data > key && curr->m_left == NULL)
            {
                curr->m_left = new tree_elem<T>(key);
                ++m_size;
                return;
            }
            if (curr->m_data < key && curr->m_right == NULL)
            {
                curr->m_right = new tree_elem<T>(key);
                ++m_size;
                return;
            }
            if (curr->m_data > key)
                curr = curr->m_left;
            else
                curr = curr->m_right;
        }
    }
    int size() {
        return m_size;
    }
    binary_tree* Where(bool (*func)(int)) {
        binary_tree* a = new binary_tree(this, func);
        return a;
    }
    binary_tree* merge(binary_tree* b) {
        binary_tree* c = new binary_tree(this);
        T* arr2 = new T[b->size()];
        arr2 = b->get_element_array(b->m_root, arr2, 0);
        for (int i = 0; i < b->m_size; i++) {
            if (arr2[i] != 0) {
                c->insert(arr2[i]);
            }
        }
        delete[] arr2;
        return c;
    }
    Sequence<T> get_sequence() {
        Sequence<T> vector = Sequence<T>();
        vector = print_tree(m_root, vector);
        return vector;
    }
};