'''
/* uva problem: 202 
 *
 * Topic: arithmetic
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   given integers a and b, find the cycle in a/b that repeats infinitely
 *
 * Solution Summary:
 *
 *   repeatedly mod out the first value and multiply by 10 until process repeats
 *   then print each modular value divided by the second number until reach the 
 *   last value modded. then print out remainders until either repetition printed
 *   or space runs out.
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
    a,b = int(line.split()[0]),int(line.split()[1])
    result = []
    result.append("%d/%d = %d." % (a, b, a / b))
    a = a % b * 10
    used = set()
    remainders = []
    while a not in used:
        remainders.append(a)
        used.add(a)
        a = a % b * 10
    i = 0
    while remainders[i] != a:
        result.append("%d" % (remainders[i] / b))
        i += 1
    result.append("(")
    j = i
    
    while i < len(remainders) and i < 50:
        result.append("%d" % (remainders[i] / b))
        i += 1
        
    if i < len(remainders):
        result.append("...")
    result.append(")\n")
    result.append("   %d = number of digits in repeating cycle\n" % (len(remainders) - j))
    print(''.join(result))