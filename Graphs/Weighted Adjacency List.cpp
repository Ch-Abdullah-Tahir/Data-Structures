#include <iostream>
using namespace std;
class Node
{
public:
    int val;       // neighbor
    int weight;    // edge weight
    Node* next;
    Node(int v, int w)
    {
        val = v;
        weight = w;
        next = NULL;
    }
};
class Graph 
{
private:
    int n;        // number of vertices
    Node** adj;   // array of linked list heads
    /*void DFS_util(int u, bool visited[]);*/
   
public:
    Graph(int size)
    {
        n = size;
        adj = new Node * [n];
        for (int i = 0; i < n; i++) {
            adj[i] = NULL;
        }
    }
    ////void BFS(int start);
    //void PrimsAlgo();
   /* void DFS(int start);*/
    void addEdge(int u, int v, int w)
    {
        insertAtTail(u, v, w);
        insertAtTail(v, u, w);   // remove for directed graph
    }

    void insertAtTail(int u, int v, int w)
    {
        Node* newNode = new Node(v, w);

        if (adj[u] == NULL)
        {
            adj[u] = newNode;
            return;
        }

        Node* temp = adj[u];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void print() 
    {
        for (int i = 0; i < n; i++) 
        {
            cout << i << ": ";
            Node* temp = adj[i];
            while (temp != NULL)
            {
                cout << "(" << temp->val << "," << temp->weight << ") ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    ~Graph() 
    {
        for (int i = 0; i < n; i++)
        {
            Node* temp = adj[i];
            while (temp != NULL) 
            {
                Node* del = temp;
                temp = temp->next;
                delete del;
            }
        }
        delete[] adj;
    }
};
