/* UVa problem: 374
*
* Topic: Number Theory
*
* Level: easy
*
* Brief problem description:
*
*   given Base value B, exponent power P, modular value M, compute x where x = B^P (mod M)
*
* Solution Summary:
*
*   Use left-to-right binary modular exponentiation method. 
*
* Used Resources:
*
*   Wikipedia article on modular exponentiation
*
* I hereby certify that I have produced the following solution myself
* using only the resources listed above in accordance with the CMPUT
* 403 collaboration policy.
*
*
* Dylan Hyatt-Denesik (Your Name)
*/

#include <iostream>

using namespace std;

int bit_mod_exp(int B,int P,int M)
{
	int result = 1;
	if (M == 1) return 0;
	while (P > 0)
	{
		if (P % 2 == 1)
			result = ((result%M) * (B%M)) % M;
		P = P >> 1;
		B = ((B%M) *(B%M)) % M;

	}

	return result;
}


int main()
{
	long int B, P, M;

	while (cin >> B >> P >> M)
		cout << bit_mod_exp(B, P, M) << endl;

	return 0;
}
