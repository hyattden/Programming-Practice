/* UVa problem: 524
 *
 * Topic: Backtracking
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   given number of integers, find cycle such that pairwise sums of adjacent numbers is prime, output in potential order
 *
 * Solution Summary:
 *
 *   Recursively check if current set of set of pairs is prime, if so for each pair, print out.
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
#include <cmath>

using namespace std;

int T,n;
int circle[20];
bool used[20];

bool is_prime(int p)
{
	for(int i=2; i<=sqrt(p); ++i)
		if(p%i == 0) return false;
	return true;	
}

void scan(int m)
{
	if(m == n-1 && is_prime(circle[n-1]+circle[n]))
	{
		for(int i=0; i<n; ++i)
			if(i == n-1)
				printf("%d",circle[i]);
			else
				printf("%d ",circle[i]);
			//printf(i == n - 1? "%d" : "%d ", circle[i]);
				//printf(i== n-1? "%d" :"%d ",circle[i]);
		printf("\n");
		return;			
	}
	for(int i=2;i<=n;++i)
	{
		if(!used[i] && is_prime(circle[m] + i))
		{
			used[i] = true;
			circle[m+1] = i;
			scan(m+1);
			used[i] = false;
		}
	}
}

int main()
{	
	T=0;
	while(scanf("%d",&n) == 1)
	{
		T++;
		if(T>1) printf("\n");
		circle[0] = circle[n] = 1;
		printf("Case %d:\n",T);
		scan(0);
	}
	return 0;
}

