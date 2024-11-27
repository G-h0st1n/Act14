//
// Created by frpat on 11/26/2024.
//

// HashTable.cpp
#include "HashTable.h"

using namespace std;

// Constructor que inicializa la tabla con un tamaño dado
HashTable::HashTable(int size, CollisionResolutionMethod method)
    : tableSize(size), method(method), numElements(0) {
    table.resize(tableSize, -1); // Initialize with -1 to indicate empty slots
    occupied.resize(tableSize, false);
}

// Función de hash que utiliza el operador módulo
int HashTable::hashFunction(int key) const {
    return key % tableSize;
}

// Linear probing
int HashTable::linearProbe(int key, int i) const {
    return (hashFunction(key) + i) % tableSize;
}

// Quadratic probing
int HashTable::quadraticProbe(int key, int i) const {
    return (hashFunction(key) + i * i) % tableSize;
}

// Insertar un elemento en la tabla
void HashTable::insert(int key) {
    if (loadFactor() >= 0.7) {
        rehash();
    }

    int i = 0, index;
    do {
        index = (method == LINEAR_PROBING) ? linearProbe(key, i) : quadraticProbe(key, i);
        if (!occupied[index]) {
            table[index] = key;
            occupied[index] = true;
            numElements++;
            return;
        }
        i++;
    } while (i < tableSize);

    cout << "Table is full, can't insert key " << key << endl;
}

// Busca un elemento en la tabla
bool HashTable::search(int key) const {
    int i = 0, index;
    do {
        index = (method == LINEAR_PROBING) ? linearProbe(key, i) : quadraticProbe(key, i);
        if (!occupied[index]) {
            return false;
        }
        if (table[index] == key) {
            return true;
        }
        i++;
    } while (i < tableSize);
    return false;
}

// Elimina un elemento de la tabla
void HashTable::remove(int key) {
    int i = 0, index;
    do {
        index = (method == LINEAR_PROBING) ? linearProbe(key, i) : quadraticProbe(key, i);
        if (!occupied[index]) {
            return;
        }
        if (table[index] == key) {
            table[index] = -1;
            occupied[index] = false;
            numElements--;
            return;
        }
        i++;
    } while (i < tableSize);
}

// Muestra la tabla hash
void HashTable::display() const {
    for (int i = 0; i < tableSize; ++i) {
        cout << "Índice " << i << ": ";
        if (occupied[i]) {
            cout << table[i] << " -> ";
        } else {
            cout << "nullptr";
        }
        cout << "\n";
    }
}

// Calcula el factor de carga
double HashTable::loadFactor() const {
    return static_cast<double>(numElements) / tableSize;
}

// Rehashing cuando la tabla está llena
void HashTable::rehash() {
    int newSize = tableSize * 2;
    vector<int> oldTable = table;
    vector<bool> oldOccupied = occupied;

    tableSize = newSize;
    table.clear();
    table.resize(tableSize, -1);
    occupied.clear();
    occupied.resize(tableSize, false);
    numElements = 0;

    for (int i = 0; i < oldTable.size(); i++) {
        if (oldOccupied[i]) {
            insert(oldTable[i]);
        }
    }
}
