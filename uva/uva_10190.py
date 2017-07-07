'''
/* UVa problem: 10190
 *
 * Topic: Arithmetic
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Given n and m, print out the sequence of quotients of repeated divisions or "boring" ir n is not power of m
 *
 * Solution Summary:
 *
 *   straightforward computation
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
    new_line = [int(i) for i in line.split()]
    n = new_line[0]
    m = new_line[1]
    out_string = str(n)
    if (n < 2) or (m < 2 ) or (m > n):
        out_string = "Boring!"
    
    while n != 1:
        if  (n < 2) or (m < 2 ) or (n  % m != 0):
            out_string = "Boring!"
            break
        n = n // m 
        out_string = out_string + " " + str(n)

    print(out_string)