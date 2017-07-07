'''
/* UVa problem: uva_10523
 *
 * Topic: Arithmetic
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Given number N and A, solve the formula from teh probelm
 *
 * Solution Summary:
 *
 *   do the formula
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
    N = int(line.split()[0])
    A = int(line.split()[1])
    count = 0
    for i in range(1,N+1):
        count += i * (A**i)    
    print(count)