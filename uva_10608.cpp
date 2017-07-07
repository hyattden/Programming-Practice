/* UVa problem: 10608
 *
 * Topic: Data Structures
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Given a set of people and their connections to other people, determine the largest connected set of people
 *
 * Solution Summary:
 *
 *   Use union find data structure to sort people by connections, then simply count largest connected set
 *
 * Used Resources:
 *
 *   Competetitive Programming 3, by Steven and Felix Halim. For union find data structure
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 * Dylan Hyatt-Denesik
 * --------------------- 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define REP(i, a, b) for (int i = int(a); i <= int(b); ++i)


using namespace std;

class UnionFind {
public:
	UnionFind(int N)
	{
	}
	~UnionFind()
	{

	}
	//create sets and representatives
	void initSet(int _size)
	{
		this->pset.resize(_size);
		REP(i, 0, _size-1 )  this->pset[i] = i;
	}

	//determine the representative of i
	int findSet(int i)
	{
		return (this->pset[i] == i) ? i : (this->pset[i] = findSet(this->pset[i]));
	}

	//combine sets containing i and j by setting representative of i to representative of j
	void unionSet(int i, int j)
	{
		this->pset[findSet(i)] = findSet(j);
	}

	//returns if i and j are in same set
	bool isSameSet(int i, int j)
	{
		return findSet(i) == findSet(j);
	}

	void reSet(int N)
	{
		this->pset.clear();
		initSet(N);
	}
	vector<int> pset; 
	int max_size;
};



int main()
{
	int cases, N, M;
	int p1, p2;

	vector<int> max_array;
	cin >> cases;
	UnionFind town(1);
	while (cases > 0)
	{
		cin >> N >> M;
		town.reSet(N);
		while (M > 0)
		{
			cin >> p1 >> p2;
			town.unionSet(p1-1, p2-1);
			--M;
		}
		--cases;
		max_array.resize(N);
		fill(max_array.begin(), max_array.end(), 0);
		for (int i = 1; i <= N; ++i)
		{
			++max_array[town.findSet(i-1)];
		}
		int it = *max_element(max_array.begin(), max_array.end());
		cout << it << endl;
	}
	
	

	
	

	cin >> N;
	return 0;
}

