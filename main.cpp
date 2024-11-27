#include "HashTable.h"
using namespace std;

int main() {
    // Tamaño de la tabla hash y método de resolución de colisiones
    int tableSize = 10;
    HashTable hashTable(tableSize, LINEAR_PROBING);  // Change to QUADRATIC_PROBING to use quadratic probing

    // Insertar elementos
    hashTable.insert(5);
    hashTable.insert(15);
    hashTable.insert(25);
    hashTable.insert(2);
    hashTable.insert(10);

    // Mostrar la tabla hash
    cout << "Tabla Hash:\n";
    hashTable.display();

    // Buscar elementos
    cout << "\nBuscar 15: " << (hashTable.search(15) ? "Encontrado" : "No encontrado") << "\n";
    cout << "Buscar 9: " << (hashTable.search(9) ? "Encontrado" : "No encontrado") << "\n";

    // Eliminar un elemento
    hashTable.remove(15);
    cout << "\nDespués de eliminar 15:\n";
    hashTable.display();

    return 0;
}

