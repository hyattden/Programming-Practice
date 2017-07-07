'''
/* kattis problem: anagramcounting
 *
 * Topic: combinatorics
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   given a set of characters, determine how many anagrams can be made
 *
 * Solution Summary:
 *
 *   Simply compute (m!)/(m1!m2!...mn!) where m is the number of characters
 *   and mi is the number of repeated characters.
 * Used Resources:
 *
 *   n/a
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *  Dylan Hyatt-Denesik
 * ---------------------
 */
'''
from collections import Counter
from math import factorial
from sys import stdin


def permutation_count(s):
    s = str(s)
    c = 1
    for i in Counter(s).values():
        c *= factorial(i)
    return factorial(len(s)) // c


def main():
    lines = []  
    for line in stdin: 
        lines.append(line.strip('\n'))
    for line in lines:
        print(permutation_count(line))
main()