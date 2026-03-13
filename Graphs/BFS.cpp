#include "Weighted Adjacency List.cpp"
#include<queue>
void Graph::BFS(int start) {
    cout << "BFS Traversal\n";
    bool *visited=new bool[n];
    queue<int>q;
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    visited[start] = true;
    q.push(start);
    while (!q.empty()) 
    {
        int i=q.front();
        cout << i << " ";
        q.pop();
        Node* temp = adj[i];
        while (temp != nullptr )
        {
            if (visited[temp->val] != true)
            {
                visited[temp->val] = true;
                q.push(temp->val);
            }
            temp = temp->next;
        }
    }
    cout << endl;
}

//int main() {
//    Graph g(5);
//
//    g.addEdge(0, 1, 10);
//    g.addEdge(0, 2, 5);
//    g.addEdge(1, 3, 2);
//    g.addEdge(3, 4, 7);
//
//    g.print();
//    g.BFS(0);
//    return 0;
//}
int main() {
    // 1. Setup a graph with 8 vertices (0 to 7)
    Graph g(8);

    // --- Component 1 (Reachability Test) ---
    // Structure: 0 -> 1 -> 4
    //          \-> 2
    //          \-> 3
    //          2 -> 4
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 5);
    g.addEdge(0, 3, 15);
    g.addEdge(1, 4, 20); // Path 0 -> 1 -> 4
    g.addEdge(2, 4, 25); // Path 0 -> 2 -> 4 (4 is reachable via multiple paths)
    g.addEdge(3, 2, 30); // Path 0 -> 3 -> 2 (Tests order and re-queue prevention)

    // --- Component 2 (Disconnected Test) ---
    // Structure: 5 -> 6 -> 7
    g.addEdge(5, 6, 35);
    g.addEdge(6, 7, 40);

    cout << "===========================================" << endl;
    cout << "       Testing BFS with Disconnected Graph" << endl;
    cout << "===========================================" << endl;

    // Print the Adjacency List
    g.print();

    // 2. BFS Starting at a node in Component 1 (0)
    // Expected output: 0 1 2 3 4 (The order of 1, 2, 3 may vary based on your insertAtTail order)
    cout << "\n--- BFS from Starting Node 0 (Component 1) ---" << endl;
    g.BFS(0);

    // 3. BFS Starting at a node in Component 2 (5)
    // This is necessary to traverse the entire graph when using a single-source BFS function.
    // Expected output: 5 6 7
    cout << "\n--- BFS from Starting Node 5 (Component 2) ---" << endl;
    g.BFS(5);

    // 4. Test starting BFS from a node that has no outgoing edges (4)
    // Expected output: 4 (Should only print the starting node)
    cout << "\n--- BFS from Starting Node 4 (Dead End) ---" << endl;
    g.BFS(4);

    cout << "\n===========================================" << endl;

    return 0;
}
