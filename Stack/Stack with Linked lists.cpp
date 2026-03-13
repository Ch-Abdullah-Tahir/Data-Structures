//#include<iostream>
//using namespace std;
//
//class node {
//    int data;
//    node* next;
//public:
//    node(int value) : data(value), next(nullptr) {}
//    void setNext(node* n)
//    {
//        next = n;
//    }
//    node* getNext() 
//    {
//        return next;
//    }
//    int getData() 
//    {
//        return data;
//    }
//};
//
//class Stack {
//    node* top;
//public:
//    Stack() : top(nullptr) {}
//
//    bool isEmpty() {
//        return top == nullptr;
//    }
//
//    void push(int value) {
//
//        node* temp = new node(value);
//        if (top == nullptr) {
//            top = temp;
//            return;
//        }
//        else {
//            temp->setNext(top);
//            top = temp;
//        }
//    }
//
//    void pop() {
//        node* topop = top;
//        top = top->getNext();
//        delete topop;
//        topop = nullptr;
//    }
//
//    int peek() {
//        if (isEmpty()) {
//            cout << "Stack is empty\n";
//            return -1;
//        }
//        return top->getData();
//    }
//
//    void display() {
//        node* curr = top;
//        cout << "[ ";
//        while (curr != nullptr) {
//            cout << curr->getData() << " ";
//            curr = curr->getNext();
//        }
//        cout << "]\n";
//    }
//};
//
//int main() {
//    Stack s;
//    s.push(10);
//    s.push(20);
//    s.push(30);
//    s.display();
//
//    cout << "Top element: " << s.peek() << endl;
//
//    s.pop();
//    s.display();
//
//    s.pop();
//    s.pop();
//    s.pop();
//
//    return 0;
//}
