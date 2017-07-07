/* UVa problem: 12210
 *
 * Topic: Graph Algorithms
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Given a complete bipartite graph, determine if there exists a matching which matches each from the left to right, if not print out how many and the smallest
 *   left vertex label
 *
 * Solution Summary:
 *
 *   Compare size of bipartite sides and sort left side, print result in format
 *
 * Used Resources:
 *
 *   ...
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 * Dylan Hyatt-Denesik
 * --------------------- (Your Name)
 */
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int cases, num_bach, num_spin, count = 0;
    int next_person;
    vector<int> bach;
    vector<int> spin;
    scanf("%d %d",&num_bach,&num_spin);

    while((num_bach != 0) && (num_spin != 0))
    {
        
        
        for (int i=0; i<num_bach; ++i)
        {
            scanf("%d",&next_person);
            bach.push_back(next_person);
        }
        for (int i=0; i<num_spin; ++i)
        {
            scanf("%d",&next_person);
            spin.push_back(next_person);
        }
        ++count;
        sort(bach.begin(),bach.end());
        if(bach.size() <= spin.size())
            printf("Case %d: %d\n",count, 0);
        
        else
            printf("Case %d: %d %d\n", count, bach.size()-spin.size(), bach[0]);
        bach.clear();
        spin.clear();
        scanf("%d %d",&num_bach,&num_spin);
    }

    return 0;
}