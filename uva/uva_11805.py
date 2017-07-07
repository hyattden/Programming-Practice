'''
/* UVa problem: 11805
 *
 * Topic: Number Theory
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   given numbers N K and P, compute (K+P)%N, except use N as representative of class N
 *
 * Solution Summary:
 *
 *   Algorithmic idea, data structures ...
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


count = -1
for line in stdin:
    count += 1
    if count == 0:
        continue
    
    numbers = line.split()
    N, K, P = int(numbers[0]), int(numbers[1]), int(numbers[2])
    if (K + P) % N != 0:
        print("Case",str(count)+":",(K+P)%N)
    else:
        print("Case",str(count)+":",N)