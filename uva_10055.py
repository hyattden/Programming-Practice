'''
/* UVa problem: 10055
 *
 * Topic: Other
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Given two numbers, print their difference
 *
 * Solution Summary:
 *
 *   Print the abs of the difference
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

for line in stdin:
    print(abs(int(line.split()[0]) - int(line.split()[1])))