#include<iostream>
using namespace std;
struct Node
{
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}

};
class LinkedList
{
public:
    void insertatHead(Node* &head, int val)
    {
        Node* temp = new Node(val);
        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
};
    Node* getIntersectionNode(Node* headA, Node* headB)
    {
        Node* iteratorA = headA;
        bool found = false;
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        else
        {
            int skipA = 0;
            int skipB = 0;
            while (iteratorA != nullptr)
            {

                Node* iteratorB = headB;
                skipB = 0;
                while (iteratorB != nullptr)
                {
                     
                    if (iteratorA == iteratorB)
                    {
                        found = true;
                        break;
                    }
                    iteratorB = iteratorB->next;
                    skipB++;
                }
                if (found == true) {
                    break;
                }
                else {
                    iteratorA = iteratorA->next;
                    skipA++;
                }
            }
            if (found) {
                cout << "Skip " << skipA << "Nodes of A  to get to the intersection\n";
                cout << "Skip " << skipB << "Nodes of B to get to the intersection\n";
                return iteratorA;
            }
            else
            {
                cout << "Linked lists don't intersect\n";
                return nullptr;
            }
        }
    }
    int main()
    {
        LinkedList a;
        Node* headA=nullptr;
        Node* headB=nullptr;
        a.insertatHead(headA, 12);
        a.insertatHead(headA, 8);
        a.insertatHead(headA, 12);
        a.insertatHead(headA, 14);
        
        LinkedList b;
        b.insertatHead(headB, 100);
        b.insertatHead(headB, 81);
        Node* common = new Node(50);
        common->next = new Node(60);
        common->next->next = new Node(70);
        Node* temp = headA;
        while (temp->next) temp = temp->next;
        temp->next = common;
       
        temp = headB;
        while (temp->next) temp = temp->next;
        temp->next = common;
        Node* ans = getIntersectionNode(headA, headB);
        if (ans!=nullptr) {
            cout <<"Intersection value= "<< ans->val;
        }
        else {
            cout << "No connection";
        }

    }