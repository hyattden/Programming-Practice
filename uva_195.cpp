/* UVa problem: 195
 *
 * Topic: Strings
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   given a string, print out the permutations in lexicographical order
 *
 * Solution Summary:
 *
 *   use next_permutation tool from algorithm with a custom comparer function to get the next_permutation and print it
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
#include <cstring>
#include <algorithm>

using namespace std;

bool comparer(char a, char b)
{
	if(tolower(a) == tolower(b)){
		return a<b;
	}
	return tolower(a) < tolower(b);
}


int main()
{
    char word[1000];
    int n;

    cin >> n;
    while (n > 0)
    {
        cin.ignore();
        cin >> word;
        n--;

        sort(word,word + strlen(word),comparer);
        cout << word << endl;
        while(next_permutation(word,word+strlen(word),comparer))
            cout << word << endl;
    }

    return 0;
}