'''
/* UVa problem: 623
 *
 * Topic: combinatorics
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   given input of integers, find factorial
 *
 * Solution Summary:
 *
 *   use factorial function from math
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
from math import factorial
from sys import stdin

for line in stdin:
    print(str(int(line))+ "!")
    print(str(factorial(int(line))))
