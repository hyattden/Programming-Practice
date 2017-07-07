/* UVa problem: 11920
 *
 * Topic: Strings
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Given string of 1's 0's and ?'s, find an assignment of the ?'s to 0 or 1's which minimized max sized group
 *
 * Solution Summary:
 *
 *   Mostly only compare case of three subsequent groups with middle being ?'s.
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

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char> left_array;
vector<char> middle_array;
vector<char> right_array;

int find_min_max_string(const string& line)
{
    int max_length = 0;
    char current_char = line[0];
    vector<char> current_array;
    vector<vector<char> > line_array;
    left_array.clear();
    middle_array.clear();
    right_array.clear();

    for (const auto &c : line)
    {
        if (c != current_char)
        {

            current_char = c;
            line_array.push_back(current_array);

	    current_array.clear();

        }
        current_array.push_back(c);
     
    }
    line_array.push_back(current_array);

    //find max length non-'?' group
    for (const auto &group : line_array)
    {
      if ((max_length < group.size()) && group[0] != '?')
	{max_length = group.size();}
    }
    if (max_length == 0)
        max_length = 1;
        
    int counter = -1;
    for (const auto &group : line_array)
    {
        left_array = middle_array;
        middle_array = right_array;
        right_array = group;
        if (middle_array.size() == 0)
            continue;

        if((left_array.size() == max_length) &&( max_length == right_array.size()) && middle_array[0] == '?')
        {
            //different characters on both sides
            if (left_array[0] != right_array[0])
            {
                //must extend end
                if (middle_array.size() == 1)
                { ++max_length; return max_length; }

				if ((middle_array.size() == 3) && (left_array.size() < 3))
				{ ++max_length; return max_length; }
		
                //#ends too short for swap truck to work
                if ((middle_array.size() % 2 == 1) && max_length == 1)
                { ++max_length; return max_length; }
            }
            //same characters on both sides
            else
            {
                //ends too short for swap trick to work
                if ((middle_array.size() % 2 == 0) && max_length == 1)
                { ++max_length; return max_length; }
            }
        }
        //solve 11?0?11 problem
		if ( (left_array.size()  == max_length) && (right_array.size() == max_length - 1) &&
			(middle_array.size() == 1 ) && (middle_array[0] == '?' ) && (left_array[0] != right_array[0]))
			right_array.push_back(right_array[0]);	
			
		
		++counter;
    }
    return max_length;
}


int main()
{
    int T;
    string string_line;
  //  vector<char> line;
    int min_max = 0;
    cin >> T;
    for(int i=0; i<T;++i)
    {
        cin >> string_line;
        min_max = find_min_max_string(string_line);
        cout << "Case " << i + 1 << ": " << min_max << endl;

    }
    return 0;
}
