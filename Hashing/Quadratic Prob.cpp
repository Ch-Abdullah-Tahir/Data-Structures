#include <iostream>
using namespace std;

const int SIZE = 11;  // size of hash table

int hashTable[SIZE];  // global table

// initialize table with -1 meaning empty
void initTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
}

// simple hash function
int hashFunc(int key) {
    return key % SIZE;
}

// insert key using linear probing
void insert(int key) {
    int i = 0;
    while (i < SIZE) {
        int index = (hashFunc(key) + i*i) % SIZE;
        if (hashTable[index] == -1) {
            hashTable[index] = key;
            return;
        }
        i++;
    }
    cout << "Table full! Cannot insert " << key << endl;
}

// search for a key
int search(int key) {
    int i = 0;
    while (i < SIZE) {
        int index = (hashFunc(key) + i*i) % SIZE;
        if (hashTable[index] == key) return index;
        if (hashTable[index] == -1) return -1;  // not found
        i++;
    }
    return -1;
}

// delete key (lazy deletion)
void remove(int key) {
    int idx = search(key);
    if (idx != -1) {
        hashTable[idx] = -2;  // -2 means deleted
        cout << "Deleted " << key << endl;
    }
    else {
        cout << key << " not found!" << endl;
    }
}

// display table
void display() {
    cout << "Hash Table: ";
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            cout << " _ ";
        else if (hashTable[i] == -2)
            cout << " X ";  // deleted
        else
            cout << hashTable[i] << " ";
    }
    cout << endl;
}

int main() {
    initTable();

    int keys[] = { 22, 41, 53, 46, 30, 13, 27, 88 };
    for (int i = 0; i < 8; i++) insert(keys[i]);

    display();

    cout << "Searching 30: ";
    int idx = search(30);
    if (idx != -1) cout << "Found at index " << idx << endl;
    else cout << "Not found!" << endl;

    remove(41);
    display();

    return 0;
}
