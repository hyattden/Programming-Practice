/* UVa problem: 10006
 *
 * Topic: number theory
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   determine if a number is prime or carmichale
 *
 * Solution Summary:
 *
 *   store first 16 carmichaels. check if given number is carmichael
 *
 * Used Resources:
 *
 *   google for first 16 carmichael numebrs
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *  Dylan Hyatt-Denesik
 * --------------------- 
 */
#include <iostream>


using namespace std;

int main()
{
	int carmichaels[15] = { 561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973 };
	int nextVal;
	bool isCarm = false;
	cin >> nextVal;
	while (nextVal != 0)
	{
		isCarm = false;
		for (int i = 0; i < 15; ++i)
		{
			if (carmichaels[i] == nextVal)
				isCarm = true;
		}
		if (isCarm)
			cout << "The number " << nextVal << " is a Carmichael number." << endl;
		else
			cout << nextVal << " is normal." << endl;


		cin >> nextVal;
	}
	return 0;
}