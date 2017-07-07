'''
/* kattis problem: spavanac
 *
 * Topic: Other
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   given time in 24 hour notation, find time 45 minutes earlier
 *
 * Solution Summary:
 *
 *   subtract 45 minutes mod 60 and 24
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
    time = [int(i) for i in line.split()]
    minute = (time[1]-45) % 60
    if time[1] - 45 < 0:
        hour = (time[0] - 1) % 24
    else:
        hour = time[0] % 24
    print(hour,minute)
    