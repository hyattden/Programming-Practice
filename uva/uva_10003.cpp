/* UVa problem: 10003
 *
 * Topic: Dynamic Programming
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Given length and set of cuts to make with cost the length of the piece being cut. Find the sequence of cuts minimizing cost.
 *
 * Solution Summary:
 *
 *   Create matrix which will store the cost of cutting that much up to that point.
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
#include <limits>

using namespace std;

#define inf numeric_limits<int>::max()


using namespace std;

int main()
{
	int l,n, cuts[51],cost[51][51];
	scanf("%d",&l);
	while (l != 0)
	{
		scanf("%d",&n);
		cuts[0] = 0;
		for (int i=1; i<=n; ++i) scanf("%d",&cuts[i]);
		n++;
		cuts[n] = l;
	
		for(int i=1; i<=n; ++i)
			for(int j=i-1; j>=0; --j)
			{
				if(j+1 == i) cost[j][i] = 0;

				else{
					cost[j][i] = inf;
					for(int k=j+1; k<i; ++k)
						cost[j][i] = min(cost[j][k] + cost[k][i], cost[j][i]);
					cost[j][i] += cuts[i] - cuts[j];
				}
				
			}
		 
		printf("The minimum cutting is %d.\n",cost[0][n]);
		scanf("%d",&l);

	}
	return 0;
}
