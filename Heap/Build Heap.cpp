#include<iostream>
using namespace std;
void heapify(int arr[],int index,int size) {
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
		heapify(arr,largest,size);
	}
	return;
}
void sortarray(int arr[],int n) {
	for (int i = n - 1; i > 0; i--) {
		swap(arr[i], arr[0]);
		heapify(arr, 0, i);
	 }
}
void BuildMaxHeap(int arr[], int n) {
	for (int i = (n / 2) -1; i >= 0; i--) {
		heapify(arr, i, n);
	}
}
void printHeap(int arr[],int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}
int main() {
	int arr[] = { 10,3,8,9,5,13,18,14,11,70 };
	BuildMaxHeap(arr, 10);
	sortarray(arr, 10);
	printHeap(arr, 10);


}