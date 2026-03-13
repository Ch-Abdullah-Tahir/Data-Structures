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
//
//int prec(const string& op) 
//{
//	if (op == "^") return 3;
//	if (op == "*" || op == "/") return 2;
//	if (op == "+" || op == "-") return 1;
//	return 0;
//}
//
//bool precedence(string stk, string input)
//{
//	if (prec(stk) == prec(input)&&stk !="^") {
//		return false;
//	}
//	else if (prec(stk) == prec(input)) {
//		return true;
//	}
//	return prec(stk) > prec(input);
//}
//
//string converter()
//{
//	//stack opstk(100);
//	//string *prefix=new string[100] ;
//	//string *input=new string[100];
//	//int count = -1;
//	//cout << "Enter . to stop\n";
//	//while(true)
//	//{
//	//	string temp;
//	//	cin >> temp;
//	//	if (temp == ".")
//	//	{
//	//		break;
//	//	}
//	//	else {
//	//		count++;
//	//		input[count]=temp;
//	//	}
//	//	
//	//}
//	////reverse the string array
//	//int start = 0;
//	//int end = count;
//	//while (start < end)//! se odd ke case ma middle element rh jana ha
//	//{
//	//	swap(input[start], input[end]);
//	//	start++;
//	//	end--;
//	//}
//	//string reversed
//	int precount = -1;
//	for (int i = 0; i <= count; i++)
//	{
//		if (opstk.isEmpty())
//		{
//			if (input[i] == "+" || input[i] == "-" || input[i] == "*" || input[i] == "/" || input[i] == ")" || input[i] == "^")
//			{
//				opstk.push(input[i]);
//			}
//			else if (input[i] == "(")
//			{
//				cout << "Invalid input,u can't enter ( on last input\n";
//			}
//			else
//			{
//				precount++;
//				prefix[precount] = input[i];
//			
//			}
//		}
//		else
//		{
//			if (input[i] == ")")
//			{
//				opstk.push(input[i]);
//			}
//			else if (input[i] == "(")
//			{
//
//				while (opstk.isEmpty() != true && opstk.peek() != ")")
//				{
//					string temp;
//					opstk.pop(temp);
//					precount++;
//					prefix[precount] = temp;
//				}
//				if (opstk.isEmpty())
//				{
//					cout << "No matching parenthisis \n";
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
//				if (input[i] == "+" || input[i] == "-" || input[i] == "*" || input[i] == "/" || input[i] == "^")
//				{
//					string temp;
//					while (!opstk.isEmpty() && precedence(opstk.peek(), input[i])) {
//						opstk.pop(temp);
//						precount++;
//						prefix[precount] = temp;
//					}
//					opstk.push(input[i]);
//				}
//				else
//				{
//					precount++;
//					prefix[precount] =  input[i];
//				}
//			}
//
//		}
//	}
//	if (opstk.isEmpty())
//	{
//
//		string ans="";
//		for (int i = precount; i >= 0; i--) {
//			ans += prefix[i];
//		}
//		delete[] prefix;
//		delete[] input;
//		return ans;
//	}
//	else
//	{
//		while (!opstk.isEmpty())
//		{
//			string temp;
//			opstk.pop(temp);
//			if (temp == ")")
//			{
//				cout << "Mismatched parenthesis\n";
//				return "";
//			}
//			precount++;
//			prefix[precount] = temp;
//		}
//		string ans = "";
//
//		for (int i = precount; i >= 0; i--)
//		{
//			ans += prefix[i];
//		}
//		delete[] prefix;
//		delete[] input;
//		return ans;
//	}
//
//
//
//
//}
//
//int main() 
//{
//	cout<<converter();
//}