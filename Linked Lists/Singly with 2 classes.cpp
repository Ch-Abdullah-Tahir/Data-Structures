//#include<iostream>
//using namespace std;
//class node
//{
//	int data;
//	node* next;
//public:
//	node() :data(0), next(nullptr) {}
//	void setData(int value)
//	{
//		data = value;
//	}
//	int getData()
//	{
//		return data;
//	}
//	void setnext(node *NEXT)
//	{
//		next = NEXT;
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
//		temp->setnext(head);
//		head = temp;
//
//		if (tail == nullptr)
//		{	// if list was empty
//			tail = temp;
//		}
//	}
//	void insertAtTail(int value) 
//	{
//		node* temp = new node();
//		temp->setData(value);
//		if (tail == nullptr)
//		{  // case 1: empty list
//			head = temp;
//			tail = temp;
//		}
//		else 
//		{                // case 2: non-empty
//			tail->setnext(temp);
//			tail = temp;
//		}
//	}
//	void insertAtMiddle(int data, int position)
//	{
//		node* temp = new node();
//		temp->setData(data);
//		if (position == 1)
//		{
//			temp->setnext(head);
//			head = temp;
//			return;
//		}
//		else
//		{
//			int start = 1;
//			node* iterator = head;
//			while (true)
//			{
//				//if (start == position - 1) {
//				//	temp->next = iterator->next;//null in case of last element
//				//	//it works fine for insertion at last,but tail does not get updated
//
//				//	iterator->next = temp;
//				//	break;
//				//}
//				//so we have to add logic for updating tail as well
//				if (start == position - 1)
//				{
//					temp->setnext(iterator->getnext());//null in case of last element
//					if (iterator->getnext() == nullptr)
//					{
//						iterator->setnext(temp);
//						tail = temp;      //updated tail as well
//						break;
//					}
//					else
//					{
//						iterator->setnext(temp);
//						break;
//					}
//				}
//				else
//				{
//					iterator = iterator->getnext();
//					start++;
//				}
//			}
//		}
//	}
//
//
//	void deleteNode(int position)
//	{
//		node* iterator = head;
//		int start = 1;
//		if (position == 1)
//		{
//			head = head->getnext();
//			delete iterator;
//			iterator = nullptr;
//			if (head == nullptr) {    // if list is empty 
//				tail = nullptr;       // reset tail as well
//			}
//			return;
//		}
//		else
//		{
//			while (start < position - 1)
//			{
//				iterator = iterator->getnext();
//				start++;
//			}
//			if (iterator->getnext()->getnext() == nullptr)
//			{
//				tail = iterator;
//				//iterator->next = iterator->next->next;
//				//iterator->next->next = nullptr;
//				delete iterator->getnext();
//				iterator->setnext(nullptr);
//			}
//			else
//			{
//				node* temp = iterator->getnext();
//				iterator->setnext(iterator->getnext()->getnext());
//				delete temp;
//				//iterator->next->next = nullptr;
//			}//tail should update if it is last
//
//		}
//	}
//
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
//	~LinkedList() {
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
//
//};
//
//int main() {
//	LinkedList a;
//	a.insertAtHead(5);
//	a.insertAtHead(2);
//	a.print();
//}