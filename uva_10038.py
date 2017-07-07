'''
/* UVa problem: 10038
 *
 * Topic: Data Structures
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Given sequence of integers, determine if they satisfy the given requirement
 *
 * Solution Summary:
 *
 *   Using an array data structure, step through to determine jolly jumper requirement of list
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
	jumper = [int(i) for i in line.split()[1:]]
	jolly = [0]*(len(jumper)-1)
	is_jolly = True
	#print(len(jumper))
	for i in range(1,len(jumper)):
		#print(i,i-1,abs(jumper[i] - jumper[i-1]))
		jumper[i]
		jumper[i-1]
		try:
			jolly[abs(jumper[i] - jumper[i-1])-1] = 1
		except:
			is_jolly = False
			break
	for jump in jolly:
		if jump == 0:
			is_jolly = False
	if is_jolly:
		print("Jolly")
	else:
		print("Not jolly")
