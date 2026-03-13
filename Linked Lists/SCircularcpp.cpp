#include<iostream>
using namespace std;
class node
{
	int data;
	node* next;
public:
	node() :data(0), next(nullptr) {}
	void setData(int value)
	{
		data = value;
	}
	int getData()
	{
		return data;
	}
	void setnext(node* NEXT)
	{
		next = NEXT;
	}
	node* getnext()
	{
		return next;
	}
};
class CLinkedList
{
	node* tail;
	int size;
public:
	CLinkedList()
	{
		tail = nullptr;
		size = 0;
	}
	void insertAthead(int value) {
		node* temp = new node();
		temp->setData(value);
		if (tail == nullptr)
		{
			tail = temp;
			tail->setnext(tail);
			size++;
		}
		else {
			temp->setnext(tail->getnext());//tail->next is head
			tail->setnext(temp);
			size++;
		}

	}
	void insertAtMiddle(int position,int value) {
		if (position == 1) 
		{
			insertAthead(value);
		}
		else {
			node* iterator = tail->getnext();
			node* temp = new node();
			int count = 1;
			temp->setData(value);
			while (count<position-1) {
				iterator = iterator->getnext();
				count++;
			}
			if(position!=2&&iterator==tail->getnext())
			{
				cout<<"Element not found\n";
			}
			else if (iterator->getnext() == tail->getnext())
			{
				insertAtTail(value);
				return;
			}
			else
			{
				temp->setnext(iterator->getnext());
				iterator->setnext(temp);
				size++;
				return;
			}
		}
	}
	void insertAtTail(int value) 
	{
		node* temp = new node();
		temp->setData(value);
		if (tail == nullptr) 
		{
			tail = temp;
			tail->setnext(tail);
			size++;
		}
		else
		{
			temp->setnext(tail->getnext());
			tail->setnext(temp);
			tail = temp;
			size++;
		}
	}
	void print() {
		if (tail == nullptr) {
			cout << "List is empty \n";
		}
		else 
		{
			node* iterator = tail->getnext();
			do
			{
				cout << iterator->getData() << " ";
				iterator = iterator->getnext();
			} while (iterator != tail->getnext());
			cout << endl;
		}
	}

	void deleteNode(int position) {
		if (tail == nullptr) {
			cout << "List is empty/n";
			return;
		}
		if (position > size) {
			cout << "Invalid position entered\n";
			return;
		}
		else if (position == 1&&tail->getnext() == tail) {
			delete tail;
			tail = nullptr;
			size--;
			return;
		}
		else if (position == 1) {
			node* todelete = tail->getnext();
			tail->setnext(tail->getnext()->getnext());
			todelete->setnext(nullptr);
			delete todelete;
			todelete = nullptr;
			size--;
			return;
		}
		else {
			node* iterator = tail->getnext();
			int i = 1;
			while (i < position - 1) {
				iterator= iterator->getnext();
				i++;
			}
			node* todelete = iterator->getnext();
			iterator->setnext(iterator->getnext()->getnext());
			todelete->setnext(nullptr);
			delete todelete;
			todelete = nullptr;
			if (i == size - 1) {
				tail = iterator;
			}
			size--;
			return;
		}
	}
};
int main() {
	CLinkedList c;
	cout << "Inserting at head\n";
	c.insertAthead(54);
	c.print();
	cout << "Inserting at head\n";
	c.insertAthead(32);
	c.print();
	cout << "Inserting at head\n";
	c.insertAthead(31);
	c.print();
	cout << "Inserting at middle\n";
	c.insertAtMiddle(1, 69);
	c.print();
	cout << "Inserting at middle\n";
	c.insertAtMiddle(4,7);
	c.print();
	cout << "Inserting at tail\n";
	c.insertAtTail(99);
	c.print();
	cout << "Inserting at middle\n";
	c.insertAtMiddle(7, 264);
	c.print();
	cout << "Deleting 3rd node\n";
	c.deleteNode(3);
	c.print();
	cout << "Deleting 6th node\n";
	c.deleteNode(6);
	c.print();
	cout << "Deleting 1st node\n";
	c.deleteNode(1);
	c.print();
	cout << "Inserting at head\n";
	c.insertAthead(196);
	c.print();
	cout << "Deleting 2nd node\n";
	c.deleteNode(2);
	c.print();
	
}