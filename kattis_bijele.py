'''
/* kattis problem: bijele
 *
 * Topic: other
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   given number of chess pieces, output difference to standard numbers
 *
 * Solution Summary:
 *
 *   print out difference
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
    pieces = [int(i) for i in line.split()]
    print(1-pieces[0],end=' ')
    print(1-pieces[1],end=' ')
    print(2-pieces[2],end=' ')
    print(2-pieces[3],end=' ')
    print(2-pieces[4],end=' ')
    print(8-pieces[5])
    