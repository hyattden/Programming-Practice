'''
/* UVa problem: 10494
 *
 * Topic: Other
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Given a sequence of equations, perform the equation
 *
 * Solution Summary:
 *
 *   Read the equation and do it
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
    equation = line.split()
    equation[0] = int(equation[0])
    equation[2] = int(equation[2])
    if equation[1] == '/':
        print(equation[0]//equation[2])
    else:
        print(equation[0] % equation[2])