'''
/* Kattis problem: lineup
 *
 * Topic: Sorting
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   given sequence of names determine if they are in order or reverse order or not
 *
 * Solution Summary:
 *
 *   get names, compare names to sorted names and reverese sorted names
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

first_line = True

names = []

for line in stdin:
	if first_line:
		first_line = False
		continue

	names.append(line)

sorted_names = []
reverse_names = []
for name in names:
	sorted_names.append(name)
	reverse_names.append(name)

sorted_names.sort()
reverse_names.sort()
reverse_names.reverse()

if names == sorted_names:
	print('INCREASING')
elif names == reverse_names:
	print('DECREASING')
else:
	print("NEITHER")

