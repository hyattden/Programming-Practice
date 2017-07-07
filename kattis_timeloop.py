'''
/* kattis problem: timeloop
 *
 * Topic: Other
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   given integer, print out a count and the word abracadra that many times
 *
 * Solution Summary:
 *
 *   Do the answer
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

count = 1
for line in stdin:
    times = int(line)
for i in range(times):
    print(count,"Abracadabra")
    count += 1