#include<iostream>
using namespace std;
class node
{
	int data;
	node* next;
	node* prev;
public:
	node() :data(0), next(nullptr), prev(nullptr) {}
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
	void setPrev(node* p)
	{
		prev = p;
	}
	node* getPrev()
	{
		return prev;
	}
	node* getnext()
	{
		return next;
	}
};
class DCLL
{
	node* tail;
	int size;
public:
	DCLL()
	{
		tail = nullptr;
		size = 0;
	}
	void insertAthead(int value)
	{
		node* temp = new node();
		temp->setData(value);
		if (tail == nullptr) {
			tail = temp;
			tail->setnext(tail);
			tail->setPrev(tail);
			size++;
			return;
		}
		else {
			temp->setnext(tail->getnext());
			temp->setPrev(tail);
			tail->getnext()->setPrev(temp);
			tail->setnext(temp);
			size++;
			return;
		}
	}
	void print_forward() {
		if (size == 0) {
			cout << "Tail is empty\n";
			return;
		}
		node* iterator = tail->getnext();
		int i = 1;
		while (i <= size) {
			cout << iterator->getData() << " ";
			iterator = iterator->getnext();
			i += 1;
		}
		cout << endl;

	}
	void print_backward() {
		node* iterator = tail;
		int i = size;
		while (i >= 1)
		{
			cout << iterator->getData() << " ";
			iterator = iterator->getPrev();
			i--;
		}
		cout << endl;

	}
	void deleteanywhere(int position) {
		if (position > size)
		{
			cout << "Invalid size\n";
		}
		else {
			if (position == 1)
			{
				if (tail->getnext() == tail) 
				{//yani ke single element ha
					delete tail;
					tail = nullptr;
					size--;
				}
				else if (tail->getnext()->getnext() == tail) 
				{//positiion 1 and list has 2 elements
					node* todel = tail->getnext();
					tail->setnext(todel->getnext());
					tail->setPrev(tail);
					delete todel;
					todel = nullptr;
					size--;
				}
				else {
					node* todel = tail->getnext();
					tail->setnext(todel->getnext());
					todel->getnext()->setPrev(tail);
					delete todel;
					todel = nullptr;
					size--;
				}
			}
			else 
			{
				node* iterator = tail->getnext();
				int i = 1;
				if (position == size) 
				{
					tail->getPrev()->setnext(tail->getnext());
					tail->getnext()->setPrev(tail->getPrev());
					node* todel = tail;
					tail = tail->getPrev();
					delete todel;
					size--;
				}
				else
				{
					while (i < position - 1)
					{
						iterator = iterator->getnext();
						i++;
					}
					iterator->setnext(iterator->getnext()->getnext());
					delete iterator->getnext()->getPrev();
					iterator->getnext()->setPrev(iterator);
					size--;
				}
			}

		}
	}
};
int main() {
	DCLL d;
	d.insertAthead(5);
	d.insertAthead(4);
	d.insertAthead(3);
	d.insertAthead(2);
	d.insertAthead(1);
	d.print_forward();
	d.print_backward();
	d.deleteanywhere(2);
	d.print_forward();

}