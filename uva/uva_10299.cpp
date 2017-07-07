/* UVa problem: 10299
 *
 * Topic: Number Theory
 *
 * Level: challenging
 * 
 * Brief problem description: 
 *
 *   Given a number, output the number of integers less than it relatively prime
 *
 * Solution Summary:
 *
 *   Use code from the code base to ouput result
 *
 * Used Resources:
 *
 *   phi.c from codebase
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 * Dylan Hyatt-Denesik
 * --------------------- (Your Name)
 */
#include <stdio.h>
#include <math.h>

int phi(int n){
  int i, count, res = 1;
  if (n == 1)
    return 0;
  for(i = 2; i*i <= n; i++){
    count = 0;
    while(n % i == 0){
      n /= i;
      count++;
    }
    if(count > 0) res *= (pow(i, count)-pow(i, count-1));
  }
  if(n > 1) res *= (n-1);
  return res;
}

int main(){
  int n;

  while(scanf("%d",&n) && n) 
    printf("%d\n", phi(n));
  return 0;
}