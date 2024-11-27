//
// Created by frpat on 11/26/2024.
//
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
using namespace std;

enum CollisionResolutionMethod {
    LINEAR_PROBING,
    QUADRATIC_PROBING
};

class HashTable {
private:
    vector<int> table;
    vector<bool> occupied;
    int tableSize;
    int numElements;
    CollisionResolutionMethod method;

    // Función de hash que utiliza el operador módulo
    int hashFunction(int key) const;
    int linearProbe(int key, int i) const;
    int quadraticProbe(int key, int i) const;

public:
    // Constructor
    HashTable(int size, CollisionResolutionMethod method);

    // Métodos de la tabla hash
    void insert(int key);
    bool search(int key) const;
    void remove(int key);
    void display() const;
    double loadFactor() const;
    void rehash();
};

#endif // HASHTABLE_H
