#include "Weighted Adjacency List.cpp"
    // Main DFS function to handle setup and cleanup
    void Graph:: DFS(int start) 
    {
        cout << "\nDFS Traversal (starting from " << start << "):\n";

        // Create a boolean array to track visited nodes.
        bool* visited = new bool[n];
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }

        // Call the recursive helper function
        DFS_util(start, visited);

        // If the graph has disconnected components, 
        // you would loop through all vertices here and call DFS_util 
        // for any unvisited ones, but for a single-source search, this is sufficient.

        cout << endl;
        delete[] visited; // Clean up
    }

    // Recursive utility function for DFS
    void Graph:: DFS_util(int u, bool visited[])
    {
        // 1. Mark the current node as visited and print it
        visited[u] = true;
        cout << u << " ";

        // 2. Recur for all the vertices adjacent to this vertex
        Node* temp = adj[u];
        while (temp != NULL)
        {
            int v = temp->val;
            if (!visited[v]) 
            {
                // If a neighbor is not visited, call DFS_util on it
                DFS_util(v, visited);
            }
            temp = temp->next;
        }
    }


    // --- Your Graph Class Definition is assumed to be here ---

    int main() {
        // Graph has 6 vertices (0 to 5)
        Graph g(6);

        // --- Undirected Edges (Based on the Adjacency List provided) ---
        // Remember: Your addEdge(u, v, w) creates (u <-> v)

        // Edges from 0
        g.addEdge(0, 1, 10); // 0 <-> 1
        g.addEdge(0, 2, 5);  // 0 <-> 2

        // Edges from 1
        // (0, 1) already added
        g.addEdge(1, 3, 15); // 1 <-> 3
        g.addEdge(1, 4, 20); // 1 <-> 4

        // Edges from 2
        // (0, 2) already added
        g.addEdge(2, 4, 25); // 2 <-> 4 (Creates cycle 0-1-4-2-0)

        // Edges from 3
        // (1, 3) already added
        g.addEdge(3, 5, 30); // 3 <-> 5

        // Edges from 4
        // (1, 4) and (2, 4) already added
        g.addEdge(4, 5, 35); // 4 <-> 5 (Creates cycle 1-3-5-4-1)

        // Edges from 5
        // (3, 5) and (4, 5) already added

        cout << "===========================================" << endl;
        cout << "       Testing DFS and BFS on 6-Node Graph" << endl;
        cout << "===========================================" << endl;

        // Print the full undirected Adjacency List
        g.print();

        // 1. Run DFS starting from Vertex 0
        cout << "\n--- Depth-First Search (DFS) ---" << endl;
        g.DFS(0);

        //// 2. Run BFS starting from Vertex 0 (for comparison)
        //cout << "\n--- Breadth-First Search (BFS) ---" << endl;
        ////g.BFS(0);

        cout << "\n===========================================" << endl;

        return 0;
    }