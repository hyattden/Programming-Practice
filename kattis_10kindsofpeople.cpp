
/* kattis problem: 10kindsofpeople
 *
 * Topic: Data Structures
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   given binary field determine if a pair of points are in teh same strongly connected component under the quartile topology
 *
 * Solution Summary:
 *
 *   run flood fill algorithm whenever a point is discovered in a field un calculated. store result and check in constant time
 *
 * Used Resources:
 *
 *   wikipedia on how to implement floodfill
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *  Dylan Hyatt-Denesik
 * ---------------------
 */

#include <iostream>
#include <vector>
#include <deque>
#include <array>
using namespace std;


//take in r1 c1 to decided which component to floodfill on and add to map
void floodFill(int &r1, int &c1, int &r_, int &c_, vector<vector<int> > &map,int &count_)
{
	int count;
	int r = r1, c = c1;
	deque<array<int, 2> > fringe;

	(map[r1][c1] > 0) ? count = count_ : count = count_*(-1);

	vector<vector<int>> seenMap;

	seenMap.resize(1000);
	for (int i = 0; i < 1000; ++i)
	{
		seenMap[i].resize(1000);
		seenMap[i].assign(1000, 0);
	}

	fringe.push_front({ r,c });

	while (fringe.size() != 0)
	{
		r = fringe[0][0];
		c = fringe[0][1];
		fringe.pop_front();

		if (seenMap[r][c] == 0)
		{
			seenMap[r][c] = 1;

			//look up one
			if ((r > 0) && (map[r - 1][c] == map[r][c]) && (seenMap[r - 1][c] != 1))
			{
				fringe.push_back({ r - 1,c });
				//map[r - 1][c] = count;
			}

			//look down  one
			if ((r < r_) && (map[r + 1][c] == map[r][c]) && (seenMap[r + 1][c] != 1))
			{
				fringe.push_back({ r + 1, c });
				//map[r + 1][c] = count;
			}

			//look left one
			if ((c > 0) && (map[r][c - 1] == map[r][c]) && (seenMap[r][c - 1] != 1))
			{
				fringe.push_back({ r,c - 1 });
				//map[r][c - 1] = count;
			}

			//look right one
			if ((c < c_) && (map[r][c + 1] == map[r][c]) && (seenMap[r][c + 1] != 1))
			{
				fringe.push_back({ r,c + 1 });
				//map[r][c + 1] = count;
			}
		}

		map[r][c] = count;
	}

	
}


//new method, assign map to 0, so 1s to positive, 0s to negative

int main()
{
	int r, c, n;
	int r1, c1, r2, c2, count = 2;
	vector<vector<int>> map;
	char b;

	cin >> r >> c;

	map.resize(1000);
	for (int i = 0; i < 1000; ++i)
	{
		map[i].resize(1000);
		map[i].assign(1000, 0);
	}



	//read in binary map, set to 1's and -1's
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> b;
			if (b - '0' == 0)
				map[i][j] = b - '0' - 1;
			else
				map[i][j] = b - '0';
		}
	}

	cin >> n;
	--r; --c;

	for (int i = 0; i < n; ++i)
	{
		cin >> r1 >> c1 >> r2 >> c2;
		--r1; --r2; --c1; --c2;

		//have we done floodfill on (r1,c1)? if not do it
		if (!(map[r1][c1] * map[r2][c2] > 1 || map[r1][c1] * map[r2][c2] < -1))
			floodFill(r1, c1, r, c, map, count);
		
		//check if its whatever
		if (map[r1][c1] == map[r2][c2])
			(map[r1][c1] < 0) ? cout << "binary" << endl : cout << "decimal" << endl;

		else
			cout << "neither" << endl;
		
		++count;

	}
	return 0;
	
}

