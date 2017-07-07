/* UVa problem: 869
 *
 * Topic: Graph Algorithms
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   given two graph descriptions, determine if they have the same connected components, irrespective of edges
 *
 * Solution Summary:
 *
 *   use adjacency matrix to represent graphs, run warshalls algorithm from competitive programming 3 to determine connected components.
 *
 * Used Resources:
 *
 *   Competitive Programming 3.
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 * Dylan Hyatt-Denesik
 * --------------------- (Your Name)
 */

#include <iostream>
#include <vector>

#define REP(i, a, b) \
for (int i = int(a); i <= int(b); ++i) 

using namespace std;

int main()
{
    int cases, num_edges;
    char v1, v2;
    int V = 26;
    bool is_same;
    int count = 0;
    
    cin >> cases;
    while(cases-- > 0)
    {    
   		if (count != 0)
   			cout << endl;
   		++count;
    	is_same = true;
    	int g1[26][26] = {0};
		int g2[26][26] = {0};	
        cin >> num_edges;
        for(int i=0; i < num_edges;++i)
        {
            cin >> v1 >> v2;
           // cout << v1 << v2 << endl;
			g1[v1 - 'A'][v2 - 'A'] = 1;
			g1[v2 - 'A'][v1 - 'A'] = 1;
        }

        cin >> num_edges;
        for(int i=0; i < num_edges; ++i)
        {
            cin >> v1 >> v2;
			g2[v1 - 'A'][v2 - 'A'] = 1;
			g2[v2 - 'A'][v1 - 'A'] = 1;
        }
		
		
        REP (k, 0, V - 1)
			REP (i, 0, V - 1)
				REP (j, 0, V - 1)
					g1[i][j] = g1[i][j] | (g1[i][k] & g1[k][j]);

        REP (k, 0, V - 1)
			REP (i, 0, V - 1)
				REP (j, 0, V - 1)
					g2[i][j] = g2[i][j] | (g2[i][k] & g2[k][j]);
		
		REP (i, 0, V - 1)
			REP (j, 0, V - 1)
				if (g1[i][j] != g2[i][j])
				 is_same = false;
		if (is_same)
			cout << "YES" << endl;
		else
			cout << "NO"  << endl;

    }   
    return 0;
}
