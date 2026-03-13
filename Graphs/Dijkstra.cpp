#include<iostream>
#include<vector>
#include<queue>
#include<vector>
using namespace std;
const int INF = 1e9;
class Graph {
	int v;//vertices
	vector<pair<int, int>>* adj;
public:
	Graph(int v)
	{
		this->v = v;
		adj = new vector< pair<int, int>>[v];
	}
	void addEdge(int u, int v, int w)//node ,neighbor,weight
	{
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });//undirected graph
	}
	void dijkstra(int src)
	{
		//initialze a distance vector of size V(all vertices) =infinity
		vector<int>dist(v, INF);
		vector<bool> visited(v, false);
		priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
		//priority queue distance,vertex
			//mark source distance with itself as 0
		dist[src] = 0;
		pq.push({ 0,src });
		while (!pq.empty())
		{
			int u = pq.top().second;//extract vertex that is shortest to reach
			pq.pop();
			if (visited[u]) continue;
			visited[u] = true;
			for (int j = 0; j < adj[u].size(); j++)
			{
				int neighbor = adj[u][j].first;
				int weight = adj[u][j].second;
				//relax edges
				if (!visited[neighbor] && dist[u] + weight < dist[neighbor])
				{
					dist[neighbor] = dist[u] + weight;
					pq.push({ dist[neighbor], neighbor });
				}
			}
		}
		// --- Print the final shortest distances ---
		cout << "Shortest distances from source " << src << ":\n";
		for (int i = 0; i < v; i++)
		{
			cout << "Node " << i << " : ";
			if (dist[i] == INF) cout << "Unreachable";
			else cout << dist[i];
			cout << endl;
		}


	}
};
int main()
{
	Graph g(5);
	g.addEdge(0, 1, 4);
	g.addEdge(0, 2, 8);
	g.addEdge(1, 2, 2);
	g.addEdge(1, 3, 5);
	g.addEdge(2, 3, 5);
	g.addEdge(2, 4, 9);
	g.addEdge(3, 4, 4);

	//Dijkstra from node 0
	g.dijkstra(0);

	return 0;
}