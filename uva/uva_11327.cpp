/* UVa problem: 11327
 *
 * Topic: Number Theory
 *
 * Level: easy
 * 
 * Brief problem description: 
 *
 *   Given integer n, find nth fraction in sequence of minimal fractions
 *
 * Solution Summary:
 *
 *   Precompute all primes up to MAXN using code base code. Then use euler phi function to compute number of fractions up to number, then count out remaining fractions.
 *
 * Used Resources:
 *
 *   Code base primes.c, gcp.cpp, eulerphi.c 
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
#include <algorithm>
#include <stdio.h>

using namespace std;

int Max_num = 200002;
#define MAXN 200002
#define MAXP 200002
long long n;
int primes[MAXP];
int psize;


long long countAt[MAXN + 1];

void getPrimes(){
  int i, j, isprime;
  
  psize = 0;
  primes[psize++] = 2;
  for(i = 3; i <= MAXN; i+= 2){
    for(isprime = j = 1; j < psize; j++){
      if(i % primes[j] == 0){
	isprime = 0;
	break;
      }
      if(1.0*primes[j]*primes[j] > i) break;
    }
    if(isprime) primes[psize++] = i;
  }
}

int isPrime(int x){
  int i;
  
  if(x <= 1) return 0;
  for(i = 0; i < psize && primes[i]*primes[i] <= x; i++){
    if(x % primes[i] == 0) return 0;
  }
  return 1;
}

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int gcd_iterative(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int phi(int n){
  int i, count, res = 1;
  
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

int main()
{
    long long n;
    int denominator;
    int count;

    getPrimes();

    countAt[0] = 0;
    countAt[1] = 1;
    countAt[2] = 2;
    for(int i=2; i<MAXN; ++i)
    {
        int temp = phi(i);
        countAt[i+1] = countAt[i] + temp;
    }
    while(scanf("%lld",&n) && n)
    {
       // printf("n1 : %lld\n",n);
        if(n==1)
            printf("0/1\n");
        else if(n==2)
            printf("1/1\n");
        else
        {
           // printf("n2 : %lld\n",n);
            denominator = (lower_bound(countAt, countAt + MAXN,n)-1) - countAt;
            n -= countAt[denominator];
            
            for(count=1; n; ++count)
                if(gcd(count,denominator) == 1)
                    --n;

            printf("%d/%d\n",count-1,denominator);
        }
    }

    return 0;
}