/* UVa problem: 105
 *
 * Topic: Data Structure
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Given set 3-tuples which describe simple integer functions. find the description of there heights
 *
 * Solution Summary:
 *
 *   store in array max heights at given index. print out in specified order
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
#include <vector>

using namespace std;

int main()
{
    int skyline[10001] = {0};
    int L, H, R;
    int current = 0;
    bool notFirst = false;
    while (!cin.eof())
    {
        cin >> L >> H >> R;

        for (int i = L; i < R; ++i )
        {
            if (skyline[i] < H)
                skyline[i] = H;
        }
    }

    for (int i = 0;i < 10001; ++i)
    {
        if(skyline[i] != current)
        {
            if (notFirst)
                cout << ' ';
            else
                notFirst = true;
            cout << i << " " <<  skyline[i];
            current = skyline[i];
        }
        
    }
    
    cout << endl;
    return 0;
}