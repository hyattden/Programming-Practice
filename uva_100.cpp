/* UVa problem: 100
 *
 * Topic: Arithmetic
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *	  given a range of numbers, find the longest sequence of numbers applying the collatz conjecture to each number inclusive of bounds, print out that length
 *
 * Solution Summary:
 *
 *   straightforward computation, nothing smart
 *
 * Used Resources:
 *
 *   n/a
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 * Dylan Hyatt-Denesik
 * --------------------- (Your Name)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)

using namespace std;



int collatz_loop(int n)
{
	if (n == 1)
	{
		//stores[n] = 1;
		return 1;
	}
	/*
	if (stores[n] != -1)
	{
		return stores[n];
	}
	*/
	

	if (n % 2 == 0)
	{
		return collatz_loop(n / 2) + 1;
	}

	//stores[n] = collatz_loop(3 * n + 1, stores) + 1;
	//cout << stores[n] << " " << n << endl;
	return collatz_loop(3 * n + 1) + 1;
	//return stores[n];
	
}
void collatz(int n, vector<int> &stores)
{
	collatz_loop(n);
}


int main()
{
	int temp = 0;
	int max= 0;
	//vector<int> stores;
	//stores.resize(1000000000);
	//stores.assign(1000000000, -1);
	vector<int> range;

	range.resize(2);
	while (scanf("%d%d", &range[0], &range[1]) != EOF)
	{
		cout << range[0] << " " << range[1] << " ";
		if (range[0] < range[1])
		{
			for (int i = range[0]; i <= range[1]; ++i)
			{
				//collatz(i, stores);
				//if (stores[i] > max)
					//max = stores[i];
				temp = collatz_loop(i);
				if (temp > max)
					max = temp;
			}
		}
		else
		{
			for (int i = range[1]; i <= range[0]; ++i)
			{
				//collatz(i, stores);
				//if(stores[i] > max)
				temp = collatz_loop(i);
				if(temp > max)
					max = temp;
			}
			
		}
		cout << max << endl;
		max = 0;
	}

	return 0;
}