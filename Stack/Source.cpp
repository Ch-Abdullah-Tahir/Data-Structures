// #include<iostream>
//using namespace std;
//
//class node {
//    string data;
//    node* next;
//public:
//    node(string value) : data(value), next(nullptr) {}
//    void setNext(node* n)
//    {
//        next = n;
//    }
//    node* getNext() 
//    {
//        return next;
//    }
//    string getData() 
//    {
//        return data;
//    }
//};
//
//class stack {
//    node* top;
//public:
//    stack() : top(nullptr) {}
//
//    bool isEmpty() {
//        return top == nullptr;
//    }
//
//    void push(string value) {
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
//    void pop() 
//    {
//        if (isEmpty()) {
//            cout << "History is empty\n";
//            return;
//        }
//        node* topop = top;
//        top = top->getNext();
//        delete topop;
//        topop = nullptr;
//    }
//
//    string peek() {
//        if (isEmpty()) {
//            cout << "Stack is empty\n";
//            return "";
//        }
//        return top->getData();
//    }
//    void deleteAll() {
//        if (isEmpty()) {
//            cout << "History is empty\n";
//            return;
//        }
//        node* deleter = top;
//        while (deleter!=nullptr) {
//            node* temp = deleter;
//            deleter = deleter->getNext();
//            delete temp;
//            temp = nullptr;
//        }
//        top = nullptr;
//        cout << "Deletion successfull\n";
//
//    }
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
//int main() {
//	stack actions;
//	int choice=-1;
//	do {
//		cout << "Enter your action \n";
//		cout << "1.type\n";
//		cout << "2.Delete\n";
//		cout << "3.Undo\n";
//        cout << "4.View all\n";
//		cout << "0.Exit\n";
//        cin >> choice;
//		if(choice == 1) {
//            actions.push("Type");
//		}
//        else if (choice == 2) {
//            actions.deleteAll();
//          
//
//        }
//        else if (choice == 3) {
//            actions.pop();
//            
//
//        }
//        else if (choice == 0) {
//            cout << "Bye Bye\n";
//            
//        }
//        else if (choice == 4) {
//            cout << "History of all actions\n";
//            actions.display();
//           
//        }
//        else {
//            cout << "Wrong input\n";
//        }
//	} while (choice != 0);
//}
