'''
/* kattis problem: carrots
 *
 * Topic: other
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   given number of contestants and problems, find number of problems
 *
 * Solution Summary:
 *
 *   print number of problems
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
    print(line.split()[1])
    break