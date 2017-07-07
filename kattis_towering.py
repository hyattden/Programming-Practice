'''
/* kattis problem: towering
 *
 * Topic: backtracking
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   given 6 boxes and 2 heights, find which boxes sum to those heights
 *
 * Solution Summary:
 *
 *   use itertools to scan through all permutations until its split into each half sums to each height
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
import itertools

def find_height(box_heights,height1,height2):
    
    
    
    pass

height1 = 0
height2 = 0

box_heights = []

for line in stdin:
    box_heights = [int(i) for i in line.split()[:-2]]
    height1 = int(line.split()[-2])
    height2 = int(line.split()[-1])
    
    attempts = list(itertools.permutations(box_heights))
    for height in attempts:
        heights = list(height)
        if height1 == sum(heights[:3]):
            list1 = heights[:3]
            list2 = heights[3:]
            list1.sort()
            list1.reverse()
            list2.sort()
            list2.reverse()
            print(*list1, sep=' ',end=' ')
            print(*list2, sep=' ')
            break
    