'''
/* UVa problem: 482
 *
 * Topic: Sorting
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   given indices and keys, sort indices and print keys
 *
 * Solution Summary:
 *
 *  sort key index pairs by index, print keys
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
line_count = 0
first_out = True
permute = []
for line in stdin:
    if first_line:
        first_line = False
        continue
    if line.strip() == "":
        continue
    if line_count % 2 == 0:
        permute = []
        temp_line = [int(i) for i in line.split()]
        for pos in temp_line:
            permute.append([pos,0])
    else:
        if first_out:
            first_out = False
        else:
            print()
        temp_line = line.split()
        for i in range(len(temp_line)):
            permute[i][1] = temp_line[i]
        #print(permute)
        permute = sorted(permute)
        for pair in permute:
            print(pair[1])
    line_count += 1
    