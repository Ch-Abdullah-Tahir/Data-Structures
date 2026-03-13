//#include <iostream>
//using namespace std;
//class Graph 
//{
//private:
//    int n;          // number of nodes
//    int** adj;      // adjacency matrix
//public:
//    // Constructor
//    Graph(int size) 
//    {
//        n = size;
//        adj = new int* [n];
//
//        for (int i = 0; i < n; i++)
//        {
//            adj[i] = new int[n];
//        }
//
//        // initialize with 0
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++) 
//            {
//                adj[i][j] = 0;
//            }
//        }
//    }
//
//    // Add edge (undirected)
//    void addEdge(int u, int v)
//    {
//        adj[u][v] = 1;
//        adj[v][u] = 1;   // delete this line for directed graph
//    }
//    // Print the matrix
//    void print()
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                cout << adj[i][j] << " ";
//            }
//            cout << endl;
//        }
//    }
//
//    // Destructor
//    ~Graph() 
//    {
//        for (int i = 0; i < n; i++) 
//        {
//            delete[] adj[i];
//        }
//        delete[] adj;
//    }
//};
//int main()
//{
//    int n = 5;
//    Graph g(n);
//
//    g.addEdge(0, 1);
//    g.addEdge(1, 2);
//    g.addEdge(3, 4);
//
//    g.print();
//
//    return 0;
//}
//
