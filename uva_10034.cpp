/* UVa problem: 10034
 *
 * Topic: Graph Algorithms
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   given a set of points on a field(freckls on back) find min spanning tree 
 *   of complete graph on those points
 *
 * Solution Summary:
 *
 *   apply Kruskals algorithm and sum total edge weights
 *
 * Used Resources:
 *
 *  given code base for graph structure and kruskal algorithms
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 * Dylan Hyatt-Denesik
 * --------------------- (Your Name)
 */

#include <algorithm>
#include <vector>
#include <utility>
#include <limits>
#include <set>
#include <cmath>
#include <iostream>
#include <iomanip>


using namespace std;

// Some basic data structures for graph storage.

// Union-Find Algorithm with Union by Rank and Path Compression
class DisjointSets {
public:
	DisjointSets(int N) : parent(vector<int>(N)), rank(vector<int>(N)) {}
	void MakeSet(int i) { parent[i] = i; rank[i] = 0; }
	void Union(int i, int j)
	{
		int iRoot = Find(i);
		int jRoot = Find(j);
		if (iRoot == jRoot) return;
		if (rank[iRoot] < rank[jRoot]) parent[iRoot] = jRoot;
		else if (rank[iRoot] > rank[jRoot]) parent[jRoot] = iRoot;
		else {
			parent[jRoot] = iRoot;
			rank[iRoot] += 1;
		}
	}
	int Find(int i)
	{
		if (parent[i] != i) parent[i] = Find(parent[i]);
		return parent[i];
	}
private:
	vector<int> parent;
	vector<int> rank;
};



struct Edge {
	Edge(int a, int b) : a(a), b(b) {}
	Edge() {}
	int a, b;
};

typedef pair<Edge, double> WeightedEdge;
typedef set<int>::iterator NodeIterator;
typedef set<int>::const_iterator ConstNodeIterator;
typedef vector<WeightedEdge>::iterator EdgeIterator;
typedef vector<WeightedEdge>::const_iterator ConstEdgeIterator;

// Graph implemented as edge list and node set.
struct Graph {
	vector<WeightedEdge> edges;	// Weighted directed edges in the graph.
	set<int> nodes;	// Keep a set of nodes around so we know how many nodes are in the graph.
	void AddEdge(int a, int b, double w)
	{
		nodes.insert(a); nodes.insert(b);
		edges.push_back(make_pair(Edge(a, b), w));
	}
	void AddBiEdge(int a, int b, double w) { AddEdge(a, b, w); AddEdge(b, a, w); }
	int NumEdges() const { return edges.size(); }
	int NumNodes() const { return nodes.size(); }
};



// Comparison function for sorting edges by edge weight.
bool EdgeWeightComp(const WeightedEdge& L, const WeightedEdge& R)
{
	return L.second < R.second;
}

// Kruskal's MST algorithm using Disjoint Sets data structure.
vector<WeightedEdge> KruskalMST(const Graph& G)
{
	DisjointSets DS(G.nodes.size());
	vector<WeightedEdge> MST;
	MST.reserve(G.NumNodes() - 1);
	for (ConstNodeIterator it = G.nodes.begin(); it != G.nodes.end(); ++it)
		DS.MakeSet(*it);
	vector<WeightedEdge> edges = G.edges;
	sort(edges.begin(), edges.end(), EdgeWeightComp);
	for (int i = 0; i < edges.size(); ++i) {
		if (DS.Find(edges[i].first.a) != DS.Find(edges[i].first.b)) {
			MST.push_back(edges[i]);
			DS.Union(edges[i].first.a, edges[i].first.b);
		}
	}
	return MST;
}

int main()
{
	int cases;
	int freckles;
	vector<vector<double> > points;
	double a, b;
	vector<WeightedEdge> MST;
	cin >> cases;
	while (cases > 0)
	{
		cin >> freckles;
		points.resize(freckles);
		Graph G;
		for (int i = 0; i < freckles; ++i)
		{
			cin >> a >> b;
			points[i] = { a,b };
		}
		for (int i = 0; i < freckles; ++i)
		{
			for (int j = 0; j < freckles; ++j)
			{
				if (i != j)
					G.AddBiEdge(i, j, sqrt((points[i][0] - points[j][0])*(points[i][0] - points[j][0]) + (points[i][1] - points[j][1])*(points[i][1] - points[j][1])));
			}
		}
		double length = 0;
		MST = KruskalMST(G);
		for (int i = 0; i < MST.size(); ++i)
		{ 
			length += MST[i].second;
		
		}
		printf("%.2f\n",length);
		--cases;
		if (cases)
			cout << endl;

	}

}
