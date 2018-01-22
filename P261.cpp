// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
// write a function to check whether these edges make up a valid tree.
// Example
// Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
// Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
// Note
// You can assume that no duplicate edges will appear in edges. 
// Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
// Tags Expand 
// Depth First Search Breadth First Search Union Find Facebook Zenefits Google

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Graph {
	int v;												// number of vertices 	
	map<int, vector<int>> adj;	  // adjacency list
	bool dfs(int v, vector<int>& visit, int parent);
	bool num(vector<int> visit);
public:
	Graph(int n);
	void addEdge(int v, int w);
	bool isCyclic();
};

Graph::Graph(int n) {
	v = n;		
	for (int i=0; i<v; ++i) {
		adj[i] = {};
		parent[i] = i;
	}
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
	adj[w].push_back(v);
}

bool Graph::num(vector<int> visit) {
	int ret = 0;
	for (auto x : visit)
		ret += x==1 ? 1 : 0;
	return ret != v;
}

bool Graph::dfs(int v, vector<int>& visit, int parent) {
	visit[v] = 1;	
	for (auto x : adj[v]) 
		if (visit[x] == 0) {
			if (dfs(x, visit, v)) return true;	
		} else {
			if (x != parent) return true;
		}	
	return false;
}

bool Graph::isCyclic() {
	vector<int> visit(v, 0);
	/*for (int i=0; i<v; ++i)
		if (visit[i] == 0)
			if(dfs(i, visit, -1))
				return true;
	*/
	return dfs(0, visit, -1) || num(visit);
}

int main() {
  Graph g1(5);
  g1.addEdge(1, 0);
  g1.addEdge(0, 2);
  g1.addEdge(2, 0);
  g1.addEdge(0, 3);
  g1.addEdge(3, 4);
  g1.isCyclic()? cout << "Graph contains cycle\n":
                 cout << "Graph doesn't contain cycle\n";

  Graph g2(3);
  g2.addEdge(0, 1);
  g2.addEdge(1, 2);
  g2.isCyclic()? cout << "Graph contains cycle\n":
                 cout << "Graph doesn't contain cycle\n";

  return 0;
}


// union and find approach
def validTree(self, n, edges):
	parent = range(n)
	def find(x):
		return x if x == parent[x] else find(parent[x])

	def union(xy):
		x, y = map(find, xy)		
		if x == y: 					 # if two vertices have a some parent means cycle occurs 
			return false
		parent[x] = y	

	return len(edges) == n-1 	
