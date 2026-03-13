//#include<iostream>
//using namespace std;
//class deque {
//	int* arr;
//	int size;
//	int front;
//	int rear;
//public:
//	deque(int s):size(s),arr(new int[size]),front(-1),rear(-1){}
//	bool isEmpty()
//	{
//		return front == -1;
//	}
//	bool isFull()
//	{
//		return front == (rear + 1) % size;
//	}
//	int Front()
//	{
//		if (isEmpty()) {
//			cout << "Queue is empty\n";
//			return -1;
//		}
//		else {
//			return arr[front];
//		}
//	}
//	int Rear() {
//		if (isEmpty()) {
//			cout << "Queue is empty\n";
//			return -1;
//		}
//		else {
//			return arr[rear];
//		}
//	}
//	void pushfront(int val) 
//	{
//		if (isFull() ){
//			cout << "Queue is full \n";
//			return;
//		}
//		else if (isEmpty()) {
//			front = rear = 0;
//		}
//		else if (front == 0) {
//			front = size - 1;
//
//		}
//		else {
//			front--;
//		}
//		arr[front] = val;
//	}
//	void pushBack(int val)
//	{
//		if (isFull()) {
//			cout << "Queue is full\n";
//			return;
//		}
//		else if (isEmpty()) {
//			front = rear = 0;
//		}
//		else if (rear == size - 1) {
//			rear = 0;
//		}
//		else {
//			rear++;
//		}
//		arr[rear] = val;
//	}
//	 int popFront() 
//	{
//		if (isEmpty()) {
//			cout << "Queue is Empty\n";
//			return -1;
//		}
//		int ans = arr[front];
//		if (front == rear) {
//			front = rear = -1;
//		}
//		else if (front == size - 1) {
//			front = 0;
//		}
//		else {
//			front++;
//		}
//		return ans;
//	}
//	int popBack() 
//	{
//		if (isEmpty()) 
//		{
//			cout << "Queue is Empty\n";
//			return -1;
//		}
//
//		int ans = arr[rear];
//		if (rear == front)
//		{
//			rear =front=-1;
//		}
//		
//		else if (rear == 0 && front !=0)
//		{
//			rear = size - 1;
//		}
//		else 
//		{
//			rear--;
//		}
//		return ans;
//	}
//};