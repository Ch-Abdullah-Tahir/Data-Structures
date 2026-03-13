#include <iostream>
#include <vector>
#include<queue>
using namespace std;
class Graph 
{
private:
    int V; // Number of vertices
    // An array of vectors. Each vector contains pairs of {neighbor, weight}
    vector<pair<int, int>>* adj;
public:
    int total_cost = 0;
    // Constructor
    Graph(int vertices)
    {
        this->V = vertices;
        adj = new vector<pair<int, int>>[V];
    }
    // Function to add an edge
    // For undirected graphs, we add the edge twice (u to v and v to u)
    void addEdge(int u, int v, int weight)
    {
        adj[u].push_back({ v, weight });
        adj[v].push_back({ u, weight });
    }
    // Function to print the graph
    void printGraph() 
    {
        for (int i = 0; i < V; i++) 
        {
            cout << "Node " << i << " connections:" << endl;

            for (int j = 0; j < adj[i].size(); j++)
            {
                int neighbor = adj[i][j].first;
                int weight = adj[i][j].second;
                cout << "  -> " << neighbor << " (weight: " << weight << ")" << endl;
            }
        }
    }

    // We will put the Prim's function here later!
    void PrimsAlgo() {
        // 1. Only two arrays needed: visited and parent
        bool* visited = new bool[V];
        int* parents = new int[V];

        for (int i = 0; i < V; i++) {
            visited[i] = false;
            parents[i] = -1;
        }

        // 2. The Min-Heap (weight, node, source)
        // We store the 'source' so we know who the parent is when we pop it
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;

        // Start with Node 0. (Weight 0, Node 0, Parent -1)
        pq.push({ 0, {0, -1} });

        int totalWeight = 0;
        int edgesCount = 0;

        while (!pq.empty()) {
            // Get the best edge
            int weight = pq.top().first;
            int u = pq.top().second.first;
            int p = pq.top().second.second;
            pq.pop();

            // If we've already included this node, ignore this edge
            if (visited[u]) continue;

            // Mark node as visited
            visited[u] = true;
            totalWeight += weight;
            parents[u] = p;

            // Print the edge (except for the start node)
            if (p != -1) {
                cout << "Edge: " << p << " - " << u << " | Weight: " << weight << endl;
            }
            cout << "Edge: " << p << " - " << u << " | Weight: " << weight << endl;
            // Add all neighbors of the current node to the queue
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                int w = adj[u][i].second;

                if (!visited[v]) {
                    pq.push({ w, {v, u} }); // Push (weight, (neighbor, current_node))
                }
            }
        }

        cout << "Final MST Weight: " << totalWeight << endl;
    }
};

int main()
{
    // Create a graph with 4 nodes (0, 1, 2, 3)
    Graph g(4);
    // Add edges
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 7);
    // Show the structure
    g.printGraph();
    g.PrimsAlgo();
    return 0;
}

