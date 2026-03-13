//#include <iostream>
//using namespace std;
////Node Structure
//class Node
//{
//public:
//    int val;
//    Node* next;
//
//    Node(int v) 
//    {
//        val = v;
//        next = NULL;
//    }
//};
//class Graph
//{
//private:
//    int n;          // number of nodes
//    Node** adj;     // array of linked lists
//    //adj is a pointer to an array
//  //  each element of the array is a Node* (head of linked list)
//    //So adj[i] = head of the adjacency list of vertex i.
//
//public:
//    Graph(int size) 
//    {
//        n = size;
//        adj = new Node *[n];
//        for (int i = 0; i < n; i++)
//        {
//            adj[i] = NULL;      // each list starts empty
//        }
//    }
//    void addEdge(int u, int v) {
//        insertAtTail(u, v);
//        insertAtTail(v, u);     // undirected graph
//    }
//
//    void insertAtTail(int u, int v) {
//        Node* newNode = new Node(v);
//
//        if (adj[u] == NULL) {
//            adj[u] = newNode;       // first node in list
//            return;
//        }
//
//        Node* temp = adj[u];
//        while (temp->next != NULL) { // go to last node
//            temp = temp->next;
//        }
//        temp->next = newNode;       // attach at tail
//    }
//
//    void print() {
//        for (int i = 0; i < n; i++) {
//            cout << i << ": ";
//
//            Node* temp = adj[i];
//            while (temp != NULL) {
//                cout << temp->val << " ";
//                temp = temp->next;
//            }
//            cout << endl;
//        }
//    }
//
//    ~Graph() {
//        for (int i = 0; i < n; i++) {
//            Node* temp = adj[i];
//            while (temp != NULL) {
//                Node* del = temp;
//                temp = temp->next;
//                delete del;
//            }
//        }
//        delete[] adj;
//    }
//};
//int main()
//{
//    Graph g(5);
//    g.addEdge(0, 1);
//    g.addEdge(0, 2);
//    g.addEdge(1, 4);
//    g.addEdge(3, 4);
//    g.print();
//    return 0;
//}
