'''/* Kattis: arithmetic
 *
 * Topic: Arithmetic
 *
 * Level: easy/challenging
 * 
 * Brief problem description: 
 *
 *   convert a number from octal to hex
 *
 * Solution Summary:
 *
 *   use built in python functions
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
    x = int(line,8)
    y = hex(x)
    print(y[2:])