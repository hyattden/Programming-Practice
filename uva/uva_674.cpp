/* UVa problem: 674
 *
 * Topic: Dynamic Programming
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Given n, find how many ways to create that number with specified coin values
 *
 * Solution Summary:
 *
 *   Just specify array which stores the number of ways to create given n for any n
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

long long int a[8000] = {1,1,1,1,1};

 int coins[4] = {5,10,25,50};

int main()
{
	int n;
	for (int i=5; i < 8000; ++i)
		a[i] = a[i-1];
	
	for (int i = 0; i < 4; ++i)
		for(int j = coins[i]; j < 8000; ++j)
			a[j] += a[j-coins[i]];
	while(scanf("%d",&n) == 1)
		printf("%d\n",a[n]);
	return 0;
}