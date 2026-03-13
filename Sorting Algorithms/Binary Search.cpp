#include<iostream>
using namespace std;
void binarySearch(int *arr,int start,int end,int target) {
	if (start > end) {
			cout << "Element not found\n";
			return;
	}
	else {
		int middle = (start + end) / 2;
		if (arr[middle] == target) {
			cout << "Element found at index " << middle << endl;
			return;
		}
		else {
			if (arr[middle] < target) {
				binarySearch(arr, middle + 1, end, target);
				//move right
			}
			else {
				binarySearch(arr, start, middle - 1, target);
				//move left
			}
		}
	}
	
}
int main() {
	int* arr = new int[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = i +1;
		cout << arr[i] << " ";
	}
	cout << endl;
	binarySearch(arr,0,9,7);
}