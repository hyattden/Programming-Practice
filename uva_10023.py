'''
/* UVa problem: 10023
 *
 * Topic: Arithmetic
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   given a number, find its square root
 *
 * Solution Summary:
 *
 *   create square root function that repeatedly searches for square root
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

def isqrt(n):
    x = n
    y = (x+1)//2
    while y < x:
        x = y
        y = (x + n // x) // 2
    return x
    
line_list = []
for line in stdin:
    line = line.strip()
    if line:
        line_list.append(line)
    
line_list = line_list[1:]
print(isqrt(int(line_list[0])))
line_list = line_list[1:]
for line in line_list:
    print("")
    print(isqrt(int(line)))