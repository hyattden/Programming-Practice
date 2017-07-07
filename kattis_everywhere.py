'''
/* kattis problem: everywhere
 *
 * Topic: Other
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   given list of names, print number of unique names
 *
 * Solution Summary:
 *
 *   use set, print size of set
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
'''
from sys import stdin

first = 1
n = 0

for line in stdin:
    if first == 1:
        first = 0
        continue
    if n ==0:
        if first == 2:
            print(len(cities))
        first = 2
        cities = set()
        n = int(line.strip())
        continue
    n-=1
    cities.add(line.strip())
print(len(cities))