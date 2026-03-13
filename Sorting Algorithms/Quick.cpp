//#include<iostream>
//using namespace std;
//void quicksort(int arr[], int start, int end) {
//	if (start == end) {
//		return;
//	}
//	int* temparr = new int[end-start+1];
//	int pivot = end-1 ;
//	int count = 0;
//	int last = pivot;
//	//int tempc = 0;
//	for (int i = start; i < pivot; i++) {
//		if (arr[i] <= arr[pivot])
//		{
//			temparr[count++] = arr[i];
//		}
//		else {
//			temparr[last--] = arr[i];
//		}
//	}
//	temparr[count] = arr[pivot];
//	for (int i = start; i < end; i++) {
//		arr[i] = temparr[i];
//	}
//
//	//left
//	quicksort(arr, start, start+count);
//	//right
//	quicksort(arr, start+count + 1, end);
//}
//int main() {
//	int arr[] = { 6,2,5,1,4,2,3 };
//	quicksort(arr, 0, 6);
//	for (int i = 0; i < 7; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
