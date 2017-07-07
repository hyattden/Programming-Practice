/* UVa problem: 10327
*
* Topic: Sorting
*
* Level: Easy
*
* Brief problem description:
*
*   Given a sequence of integers, determine how many bubble sort swaps are needed to sort the list
*
* Solution Summary:
*
*   implement bubble sort and count each swap
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
* ---------------------
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int bubble_sort(vector<int> list)
{
	int i, j, temp;
	int swaps = 0;
	for (int i = 0; i < list.size(); ++i)
	{
		for (int j = 0; j < list.size() - i - 1; ++j)
		{
			if (list[j] > list[j + 1])
			{
				temp = list[j + 1];
				list[j + 1] = list[j];
				list[j] = temp;
				swaps++;
			}
		}
	}
	return swaps;
}

int main()
{
	int N = 0;
	vector<int> list;

	while (scanf("%d", &N) == 1)
	{
		list.resize(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> list[i];
		}
		cout << "Minimum exchange operations : " << bubble_sort(list) << endl;
	}
	return 0;
}
