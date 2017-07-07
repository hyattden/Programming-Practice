


/* UVa problem: 10714
 *
 * Topic: geometry
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   given ants in a line, find fastest and slowest times for ants to leave live
 *
 * Solution Summary:
 *
 *   noting ants basically don't touch each other, find max and min travel times
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

using namespace std;

int main()
{
	int length, num_ants, instances;
	int next_ant, extremal_ant = 0, middle_ant = 0;

	cin >> instances;

	while(instances > 0)
	{
		cin >> length >> num_ants;
		extremal_ant = length;
		while (num_ants > 0)
		{
			cin >> next_ant;

			//store extremal_ant as minimal as possible
			if (next_ant < extremal_ant || length - next_ant < extremal_ant)
				extremal_ant = min(next_ant, length - next_ant);
			
			if (next_ant > middle_ant && next_ant < length - middle_ant)
				middle_ant = min(next_ant, length - next_ant);
			
			num_ants--;
		}
		cout << min(middle_ant, length - middle_ant) << " " << max(extremal_ant, length - extremal_ant) << endl;
		instances--;
		extremal_ant = 0;
		middle_ant = 0;
	}

	return 0;
}