'''
/* kattis problem: r2
 *
 * Topic: other
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   given value and a mean, find other value used to get mean
 *
 * Solution Summary:
 *
 *   using mean formula, calculate other vale
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
    values = [int(i) for i in line.split()]
    print(2*values[1] - values[0])