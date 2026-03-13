#include<iostream>
using namespace std;
class MaxHeap {
	int* arr;
	int size;//total elements in heap
	int total_size;
public:
	MaxHeap(int n):arr(new int[n]),size(0),total_size(n){}
	void insert(int value)//step up
	{
		//if heap size is availabe or not
		if (size == total_size)
		{
			cout << "Heap overflow\n";
			return;
		}
		arr[size] = value;
		int index = size;
		size++;
		while (index > 0 && arr[(index - 1) / 2] < arr[index]) 
		{
			//parent is less
			swap( arr[(index - 1) / 2], arr[index]);
			index = (index - 1) / 2;

		}
		cout << arr[index] << "is inserted into the heap\n";
		return;
	}
	void heapify(int index) {//step down
		int largest = index;
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		if (left<size && arr[left]>arr[largest])
		{
			largest = left;
		}
		if (right<size && arr[right]>arr[largest])
		{
			largest = right;
		}
		if (largest != index) {
			swap(arr[index], arr[largest]);
			heapify(largest);
		}
		return;

	} 
	void Delete()//step down
	{
		if (size == 0)
		{
			cout << "Heap underflow\n";
			return;
		}
		cout << arr[0] << "deleted from te heap\n";
		arr[0] = arr[size - 1];
		size--;
		if (size == 0)
		{
			return;
		}
		heapify(0);
		return;
	}
	
};
int main() {
	MaxHeap h1(10);
}