#include<iostream>
#include<stack>
using namespace std;
int main() {
	stack<int> st;
	stack<int> st2;
	for (int i = 0; i < 12; i++) {
		st.push(i);
	}
	for (int i = 0; i < 12; i++) {
		st2.push(st.top());
		st.pop();
	}
	for (int i = 0; i < 12; i++) {
		cout << st2.top();
		st2.pop();
	}
}