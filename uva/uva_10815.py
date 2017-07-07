'''
/* UVa problem: 10815
 *
 * Topic: Data Structures: dictionary
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   given input, sort out
 *
 * Solution Summary:
 *
 *   get each line, regex out alphabetical characters, store in set, when done stepping, convert set to list, sort, print
 *
 * Used Resources:
 *
 *   stack overflow for information on regex
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * Dylan Hyatt-Denesik
 * --------------------- (Your Name)
 */
 '''

from sys import stdin
import re


D = {}
endset = set()
lines = []
for line in stdin: 
  templine = line.lower()
  S = re.findall('[a-zA-Z]+',templine)
  newset = set()
  for w in S:
    endset.add(w)
out = list(endset)
out.sort()
#print(out)
for element in out:
  print(element)