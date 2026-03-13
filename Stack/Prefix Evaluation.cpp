#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class stack
{
	int size;
	string* ptr;
	int top;
public:
	stack() :size(100), ptr(new string[size]), top(-1) 
	{
		cout << "Stack created\n";
	}
	bool isEmpty() {
		return(top == -1);
	}
	bool isFull() {
		return (top == size - 1);
	}
	void push(string s)
	{
		if (!isFull())
		{
			top++;
			ptr[top] = s;
		}
		else
		{
			cout << "Stack is full bro\n";
			return;
		}
	}
	bool pop(string& s) {
		if (isEmpty()) {
			//cout << "Stack is empty\n";
			return false;
		}
		else {
			s = ptr[top];
			top--;
			return true;

		}
	}
	int gettop() {
		return top;
	}
	string peek()
	{
		return ptr[top];
	}
	void print() {
		if (!isEmpty())
		{
			for (int i = 0; i <= top; i++)
			{
				cout << ptr[i] << " ";
			}
			cout << endl;
		}
	}
	~stack() {
		delete[] ptr;
		cout << "Stack deleted\n";
	}
}
int converter() {
	cout << "Converter ma agye\n";
	stack opstk;
	string* input = new string[100];
	int count = -1;
	cout << "Enter . to stop\n";
	while (true)
	{
		string temp;
		cin >> temp;
		if (temp == ".")
		{
			break;
		}
		else {
			count++;
			input[count] = temp;
		}

	}//inputs taken now we will move R to L easily 

	for(int i=count;i>=0;i--)
	{
		
		 if (input[i] == "+" || input[i] == "-" || input[i] == "*" || input[i] == "/" || input[i] == "^")
		{
			if (opstk.isEmpty()) 
			{
			cout<<	"Incorrect,prefix\n";
				return -1;
			}
			else if (opstk.gettop() == 0) {
				cout << "There is only one operand on stack \n";//can't pop mf
				return -1;
			}
			else {
				string s;
				opstk.pop(s);
				int op1 = stoi(s);
				opstk.pop(s);
				int op2 = stoi(s);
				int ans = 0;
				if (input[i]== "+") {
					ans = op1 + op2;
				}
				else if (input[i] == "-")
				{
					ans = op1 - op2;
				}
				else if (input[i] == "*") {
					ans = op1 * op2;
				}
				else if (input[i] == "/") {
					ans = op1 /op2;
				}
				else if (input[i] == "^") {
					ans = pow(op1,op2);
				}
				opstk.push(to_string(ans));
			}
			
		}
		else 
		{
			opstk.push(input[i]);
		}
	}
	string res;
	opstk.pop(res);
	delete[] input;
	return stoi(res);

}

int main() {
	cout << "Prefix evaluator \n";
	cout << converter();
	
}