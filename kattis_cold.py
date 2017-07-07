'''
/* kattis problem: cold
 *
 * Topic: other
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   given set of tempuratures, find amount less than zero
 *
 * Solution Summary:
 *
 *   scan input for ints less than zero
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

first_line = True
for line in stdin:
    if first_line:
        first_line = False
        continue
    temps = [int(i) for i in line.split()]
    count = 0
    for temp in temps:
        if temp < 0:
            count += 1
    print(count)