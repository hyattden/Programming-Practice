'''/* UVa problem: 375
 *
 * Topic: Dynamic Programming
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Given n, find how many ways to create that number with specified coin values
 *
 * Solution Summary:
 *
 *   Just specify array which stores the number of ways to create given n for any n, same as uva_674, except integer overflow was problem for C,
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

A = [1]*30005
#print(len(A))
coins = [5,10,25,50]
for i in range(0,4):
    for j in range(coins[i],30005):
        #print(j-coins[i])
        A[j] += A[j - coins[i]]
for line in stdin:
    if A[int(line)] == 1:
        print("There is only 1 way to produce",int(line),"cents change.")
    else:
        print("There are",A[int(line)],"ways to produce",int(line),"cents change.")