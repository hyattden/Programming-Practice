'''
/* kattis problem: namethatpermutation
 *
 * Topic: Combinatorics
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   given an n numbers and an index i , find the ith lexicographic permuation of the n numbers
 *
 * Solution Summary:
 *
 *   knowing there are |elems|! permutations, the n//|elems|! finds the nth one, remove it
 *   and recurse on teh remainder
 *
 * Used Resources:
 *
 *   wikipedia for description of factoradics and how they relate to the problem
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 * Dylan Hyatt-Denesik
 * --------------------- 
 */
'''

from math import factorial
from sys import stdin

def nthPerm(n,elems):#with n from 0
    if(len(elems) == 1):
        return str(elems[0])
    size = factorial(len(elems)-1)
    q = n//size
    r = n % size
    v = elems[q]
    elems.remove(v)
    str(v)
    return str(v) + ' ' + nthPerm(r,elems)

def main():
    for line in stdin:
        line = line.split()
        values = list(range(1,int(line[0])+1))    
        print(nthPerm(int(line[1]),values))
#main()