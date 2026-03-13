//#include<iostream>
//using namespace std;
//class stack
//{
//	int size;
//	string* ptr;
//	int top;
//public:
//	stack() :size(100), ptr(new string[size]), top(-1)
//	{
//		cout << "Stack created\n";
//	}
//	bool isEmpty() {
//		return(top == -1);
//	}
//	bool isFull() {
//		return (top == size - 1);
//	}
//	void push(string s)
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
//	bool pop(string& s) {
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
//	int gettop() {
//		return top;
//	}
//	string peek()
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
//};
//string converter() {
//	stack opstk;
//	string* input = new string[100];
//	int count = -1;
//	cout << "Enter . to stop\n";
//	while (true)
//	{
//		string temp;
//		cin >> temp;
//		if (temp == ".")
//		{
//			break;
//		}
//		else {
//			count++;
//			input[count] = temp;
//		}
//
//	}
//	for(int i=0;i<=count;i++)
//	{
//		if (input[i] == "+" || input[i] == "-" || input[i] == "*" || input[i] == "/" || input[i] == "^")
//		{
//			if (opstk.isEmpty())
//			{
//				cout << "Incorrect,postfix\n";
//				return "";
//			}
//			else if (opstk.gettop() == 0)
//			{
//				cout << "There is only one operand on stack \n";//can't pop mf
//				return "";
//			}
//			else
//			{//a b +
//				string op1 = "";
//				string op2 = "";
//				opstk.pop(op2);//b
//				opstk.pop(op1);//a
//				string pushstr = "(" + input[i] + op1 + op2+")";
//				opstk.push(pushstr);
//			}
//		}
//		else 
//		{
//			opstk.push(input[i]);
//		}
//
//	}
//	string res;
//	opstk.pop(res);
//	delete[] input;
//	return res;
//}
//int main() {
//	cout << "Postfix to Prefix converter\n";
//	cout << converter();
//}