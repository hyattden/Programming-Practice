'''
/* UVa problem: 495
 *
 * Topic: Number Theory
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Given sequence of numbers of numbers in range 0-5000, output that fibonacci number
 *
 * Solution Summary:
 *
 *   Pre-compute first 5000 fibonacci numbers, store in list, output
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

def fib(n1, n2):
    fib_numbers = []
    for i in range(5001):
        fib_numbers.append(n1+n2)
        temp = n1
        n1 = n2 + n1
        n2 = temp
    return fib_numbers

fib_number = fib(0, 1)
for line in stdin:
    if int(line) == 0:
        print("The Fibonacci number for", line.strip() , "is", str(0) )
    else:
        print("The Fibonacci number for", line.strip() , "is", str(fib_number[int(line)-1]) )