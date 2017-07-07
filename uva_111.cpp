/* UVa problem: 111
 *
 * Topic: Dynamic Programming
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   given a sequence of n integers, find the size of the longest increasing subsequence of following permutations
 *
 * Solution Summary:
 *
 *   Just count size of longest increasing subsequence
 *
 * Used Resources:
 *
 *   wikipedia description of longest increasing subsequence
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

using namespace std;
int X[22] = { 0 };


void longest_increasing_subsequence(vector<int> store, int N)
{
	int max;                        
	int largest = 0;                

	for (int i = 1; i <= N; ++i)    
	{
		max = 0;                    
		for (int j = i - 1; j >= 0; --j)
		{
			if (store[i] > store[j])
				if (X[j] > max)
					max = X[j];     
		}
		X[i] = max + 1;             
		if (max > largest)           
		{
			largest = max;          
		}

	}
	cout << largest + 1 << endl;
}

int main()
{
	int N;
	int temp;
	vector<int> store;
	vector<int> inputSequence;

	//get number of questions and proper order of events
	cin >> N;
	inputSequence.resize(22);
	store.resize(22);
	for (int i = 0; i<N; ++i)
		cin >> inputSequence[i];

	while (cin >> temp)                  
	{
		store[temp] = inputSequence[0];

		for (int i = 1; i<N; ++i)         
		{
			cin >> temp;   
			store[temp] = inputSequence[i];
		}
		longest_increasing_subsequence(store, N);
	}
	return 0;
}
