//#include<iostream>
//using namespace std;
//class stack 
//{
//	string* ptr;
//	int size;
//	int top;
//public:
//	stack(int s) :size(s), ptr(new string[s]), top(-1)
//	{
//	}
//	bool isEmpty() 
//	{
//		return(top == -1);
//	}
//	bool isFull() 
//	{
//		return (top == size - 1);
//	}
//	void push(const string& s)
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
//	bool pop(string& s)
//	{
//		if (isEmpty())
//		{
//			//cout << "Stack is empty\n";
//			return false;
//		}
//		else
//		{
//			s = ptr[top];
//			top--;
//			return true;
//
//		}
//	}
//	string peek()
//	{
//		if (isEmpty()) return "";
//		return ptr[top];
//	}
//	void print()
//	{
//		if (!isEmpty())
//		{
//			for (int i = 0; i <= top; i++)
//			{
//				cout << ptr[i] << " ";
//			}
//			cout << endl;
//		}
//	}
//	~stack() 
//	{
//		delete[] ptr;
//		
//	}
//
//};
//int prec(const string& op) {
//	if (op == "^") return 3;
//	if (op == "*" || op == "/") return 2;
//	if (op == "+" || op == "-") return 1;
//	return 0;
//}
//
//bool precedence(string stk, string input)
//{
//	if (stk == "^" && input == "^") return false;
//	return prec(stk) >= prec(input);
//}
//
//string converter()
//{
//	stack opstk(100);
//	string postfix = "";
//	string input;
//	cout << "Enter . to stop\n";
//	while (cin >> input)
//	{
//		if (input == ".") 
//		{
//			if (opstk.isEmpty())
//			{
//				return postfix;
//			}
//			else 
//			{
//				while (!opstk.isEmpty())
//				{
//					string temp;
//					opstk.pop(temp);
//					if (temp == "(")
//					{
//						cout << "Mismatched parenthesis\n";
//						return "";
//					}
//					
//					postfix += temp;
//				}
//				return postfix;
//			}
//		}
//		if (opstk.isEmpty())
//		{
//			if (input == "+" || input == "-" || input == "*" || input == "/" || input == "("||input=="^")
//			{
//				opstk.push(input);
//			}
//			else if (input == ")")
//			{
//				cout << "Invalid input,u can't enter ) on first input\n";
//			}
//			else
//			{
//				postfix += input;
//			}
//		}
//		else
//		{
//			if (input == "(")
//			{
//				opstk.push(input);
//			}
//			else if (input == ")")
//			{
//
//				while (opstk.isEmpty() != true && opstk.peek() != "(")
//				{
//					string temp;
//					opstk.pop(temp);
//					postfix += temp;
//				}
//				if (opstk.isEmpty())
//				{
//					cout << "No matching parenthisis for ) was found,program terminated\n";
//					return "";
//				}
//				else
//				{
//					string a;
//					opstk.pop(a);//( popped
//				}
//
//			}
//			else
//			{
//				if (input == "+" || input == "-" || input == "*" || input == "/"||input=="^")
//				{
//					string temp;
//					while (!opstk.isEmpty() && precedence(opstk.peek(), input)) {
//						opstk.pop(temp);
//						postfix += temp;
//					}
//					opstk.push(input);
//				}
//				else 
//				{
//					postfix += input;
//				}
//			}
//		}
//	}
//	
//}
//int main() 
//{
//	cout<<converter();
//}