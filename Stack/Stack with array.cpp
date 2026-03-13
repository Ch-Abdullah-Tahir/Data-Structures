//#include<iostream>
//using namespace std;
//class stack {
//	int* ptr;
//	int size;
//	int top;
//public:
//	stack(int s):size(s),ptr(new int[s]),top(-1) {
//		cout << "Stack created\n";
//	}
//	bool isEmpty() {
//		return(top == -1);
//	}
//	bool isFull() {
//		return (top == size - 1);
//	}
//	void push(int s)
//	{
//		if (!isFull())
//		{
//			top++;
//			ptr[top] = s;
//		}
//		else
//		{
//			cout << "Stack is full bro\n";
//			return;
//		}
//	}
//	bool pop(int& s) {
//		if (isEmpty()) {
//			//cout << "Stack is empty\n";
//			return false;
//		}
//		else {
//			s = ptr[top];
//			top--;
//			return true;
//
//		}
//	}
//	int peek()
//	{
//		return ptr[top];
//	}
//	void print() {
//		if (!isEmpty())
//		{
//			for (int i = 0; i <= top; i++) 
//			{
//				cout << ptr[i] << " ";
//			}
//			cout << endl;
//		}
//	}
//	~stack() {
//		delete[] ptr;
//		cout << "Stack deleted\n";
//	}
//
//};
//int main() {
//	stack a(5);
//	int val = 0;
//	if (a.pop(val)) {
//		cout << "Value\n";
//	}
//	else {
//		cout << "Stack is empty\n";
//	}
//	a.push(32);
//	a.push(45);
//	a.print();
//	cout << "Peek is " << a.peek() << endl;;
//}