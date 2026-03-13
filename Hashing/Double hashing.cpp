#include<iostream>
using namespace std;
const int SIZE = 11;
int hashmap[SIZE];
int hash1(int key)
{
	return key%SIZE;
}
int hash2(int key) 
{
	return 7 - (key % 7);
}
void initialize() 
{
	for (int i = 0; i < SIZE; i++)
	{
		hashmap[i] = -1;
	}
}
void insert(int key) {
	int i = 0;
	while (i < SIZE)
	{
		int index = (hash1(key) + (i * hash2(key))) % SIZE;
		if (hashmap[index] == -1) {
			hashmap[index] = key;
			return;
		}
		i++;
	}
}
int DoubleHashsearch(int key) {
	int i = 0;
	while (i < SIZE) {
		int index = (hash1(key) + (i * hash2(key))) % SIZE;
		if (hashmap[index] == key) return index;
		if (hashmap[index] == -1) return -1;  // not found
		i++;
	}
	return -1;
}
void DoubleHashDelete(int key) {
	int idx = DoubleHashsearch(key);
	if (idx != -1) {
		hashmap[idx] = -2;  // -2 means deleted
		cout << "Deleted " << key << endl;
	}
	else {
		cout << key << " not found!" << endl;
	}
}
void display()
{
cout << "Hash Table: ";
for (int i = 0; i < SIZE; i++)
{
	if (hashmap[i] == -1)
	cout << " _ ";
	else if (hashmap[i] == -2)
	cout << " X ";  // deleted
	else
	cout << hashmap[i] << " ";
		
}
		cout << endl;
}
int main() {
	initialize();
	int Keys[] = {22, 41, 53, 46, 30, 13, 27, 88};
	  for (int i = 0; i < 8; i++) insert(Keys[i]);
	    display();
	
}