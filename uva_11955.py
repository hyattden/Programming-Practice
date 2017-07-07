'''
/* UVa problem: 11955
 *
 * Topic: Arithmetic
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   given binomial coefficient find expansino
 *
 * Solution Summary:
 *
 *   implement basic binomial expansion
 *
 * Used Resources:
 *
 *   wikipedia on binomial expansino
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

from math import factorial
from sys import stdin
import re

def ncr(n,r):
    f = factorial

    return f(n)//f(n-r)//f(r)


def main():
    lines = []
    for line in stdin: 
        lines.append(line.strip('\n'))
    n = int(lines[0])
    lines = lines[1:]
    for i in range(n):
        print("Case " + str(i+1) + ": ", end="")
        var1 = re.search(r'[a-z]+',lines[i],re.I|re.M)
        var1 = var1.group(0)
        var2 = re.search(r'\+[a-z]+',lines[i],re.I|re.M)
        var2 = var2.group(0)[1:]
        power = re.search(r'[0-9]+', lines[i])
        power = int(power.group())
        
        if power == 1:
            print(var1 + "+" + var2)
        else:
            for j in range(power+1):
                coef = ncr(power,j)
                if coef == 1:
                    if j == 0:
                        print(var1+"^"+str(power)+"+",end="")
                    else:
                        print(var2+"^"+str(power))
                        
                        
                elif coef == power:
                    if j == power-j:
                        print(str(coef)+"*"+var1+"*"+var2+"+",end="")
                    elif j == 1:
                        print(str(coef)+"*"+var1+"^"+str(power-j)+"*"+var2+"+",end="")
                    else:
                        print(str(coef)+"*"+var1+"*"+var2+"^"+str(j)+"+",end="")
                else:
                    print(str(coef)+"*"+var1+"^"+str(power-j)+"*"+var2+"^"+str(j)+"+",end="")
        
        
main()