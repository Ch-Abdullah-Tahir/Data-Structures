//#include<iostream>
//using namespace std;
//class node
//{
//	int data;
//	node* next;
//	node* prev;
//public:
//	node() :data(0), next(nullptr), prev(nullptr){}
//	void setData(int value)
//	{
//		data = value;
//	}
//	int getData()
//	{
//		return data;
//	}
//	void setnext(node* NEXT)
//	{
//		next = NEXT;
//	}
//	void setPrev(node* p)
//	{
//		prev = p;
//	}
//	node* getPrev()
//	{
//		return prev;
//	}
//	node* getnext()
//	{
//		return next;
//	}
//};
//
//class LinkedList
//{
//	node* head;//inko separate likhen to 
//	node* tail;
//public:
//	LinkedList()
//	{
//		head = nullptr;
//		tail = nullptr;
//	}
//	void insertAtHead(int value)
//	{
//		node* temp = new node();
//		temp->setData(value);
//		if (head != nullptr)
//		{
//			head->setPrev(temp);
//			temp->setnext(head);
//			head = temp;
//			
//		}
//		else
//		{
//			head = temp;
//			tail = temp;
//		}
//
//	}
//	void insertAtTail(int value)
//	{
//		node* temp = new node();
//		temp->setData(value);
//
//		if (tail != nullptr) 
//		{
//			tail->setnext(temp);
//			temp->setPrev(tail);
//			tail = temp;
//		}
//		else
//		{ 
//			head = tail = temp;
//		}
//	}
//
//	void insertAtMiddle(int data, int position)
//	{
//		
//		if (position == 1)
//		{
//			insertAtHead(data);
//			return;
//		} 
//		node* temp = new node();
//		temp->setData(data);
//		node* iterator = head;
//		int count = 1;
//		while (count != position-1) 
//		{
//			iterator = iterator->getnext();
//			count++;
//		}
//		if (iterator->getnext() == nullptr) 
//		{
//			insertAtTail(data);
//			return;
//		}
//		temp->setnext(iterator->getnext());
//		temp->setPrev(iterator);
//		iterator->setnext(temp);
//		temp->getnext()->setPrev(temp);
//
//	}
//	void deleteNode(int position)
//	{
//		if (head == nullptr)
//		{
//			cout << "List is empty\n";
//		}
//		else if (position == 1)
//		{
//			if (head->getnext() == nullptr) 
//			{
//				delete head;
//				tail=head = nullptr;
//
//			}
//			else
//			{
//				head = head->getnext();
//				head->getPrev()->setnext(nullptr);
//				delete head->getPrev();
//				head->setPrev(nullptr);
//			}
//		}
//		else
//		{    //we assume we don't get length mismatch
//			node* iterator = head;
//			int count = 1;
//			while (iterator!=nullptr)
//			{
//				if (count == position)
//				{
//					break;
//				} 
//				count++;
//				iterator = iterator->getnext();
//			}
//			if (iterator == nullptr) 
//			{
//				cout << "Element not found\n";
//				return;
//			}
//			else if (iterator->getnext() == nullptr)//tail ha
//			{
//				tail = iterator->getPrev();
//				tail->setnext(nullptr);
//				iterator->setPrev(nullptr);
//				delete iterator;
//				iterator = nullptr;
//				return;
//			}
//			else
//			{
//				iterator->getPrev()->setnext(iterator->getnext());
//				iterator->getnext()->setPrev(iterator->getPrev());
//				iterator->setnext(nullptr);
//				delete iterator;
//				//iterator->setPrev(nullptr);
//
//			}
//			
//		}
//	}
//		
//	void print()
//	{
//		node* temp = head;
//		while (temp != nullptr)
//		{
//			cout << temp->getData() << " ";
//			temp = temp->getnext();
//		}
//		cout << endl;
//	}
//	~LinkedList()
//	{
//		node* current = head;
//		while (current != nullptr) //next pe move krwaya hua ab jab last ke next pe move krke aye ga tou wo null ko point krta hoga
//		{
//			node* nextNode = current->getnext();
//			delete current;
//			current = nextNode;
//		}
//		head = tail = nullptr;
//	}
//
//};
//int main() 
//{
//	LinkedList a;
//	a.insertAtHead(5);
//	a.insertAtHead(51);
//	a.insertAtHead(1);
//	a.print();
//	a.insertAtMiddle(4,3);
//	a.print();
//	a.insertAtTail(100);
//	a.print();
//	a.deleteNode(1);
//	a.print();
//	a.insertAtTail(21);
//	a.deleteNode(4);
//	a.print();
//	a.deleteNode(2);
//	a.print();
//}