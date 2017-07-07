'''
/* Kattis: flyingsafely
 *
 * Topic: Graph Traversal
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Given a graph description, determine minimum number of edges to reach each edge
 *
 * Solution Summary:
 *
 *   solution is size of tree, which is number of nodes minus one which is given in input
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

line_count = 0
flight_count = 0
n = 0
for line in stdin:
  if line_count == 0:
    line_count += 1
    continue
  if flight_count == 0:
    line = line.split(" ")
    n = int(line[0])
    print(n-1)
    flight_count = int(line[1])
    continue
  flight_count -= 1