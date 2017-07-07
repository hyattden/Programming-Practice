'''
/* kattis problem: oddities
 *
 * Topic: other
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   given number, print if its odd or even
 *
 * Solution Summary:
 *
 *   print if its odd or even
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

first =1 

for line in stdin:
    if first:
        first = 0
        continue
    if int(line.strip()) % 2 == 0:
        print(line.strip(),"is even")
    else:
        print(line.strip(),"is odd")