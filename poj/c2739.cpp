#include<bits/stdc++.h>
using namespace std;

// Accepted :)
// idea
// |lo|------|hi|
//    |----sum--|
int N = 10000;
vector<int> primes;
bool isPrimeSlow(int x) {
  for (int i=2; i<=sqrt(x); ++i)
    if (x%i == 0) return false;
  return true;
}

//ref:https://en.wikipedia.org/wiki/Primality_test 
bool isPrime(int n) {
  if (n <= 1) return false;
  else if (n <= 3) return true;
  else if (n%2==0 || n%3==0) return false;
  int k = 5;
  while (k*k <= n) {
    // 6k-1       6k+1
    if (n%k==0 || n%(k+2)==0) 
      return false;
    k = 6+k;
  }
  return true;
}

int main() {
  for (int i=2; i<=N; ++i)
    if (isPrime(i))
      primes.push_back(i);

  int x;
  while (cin >> x && x) {
    int cnt = 0;
    int sum = 0;
    int lo=-1;
    for (int hi=0; lo<=hi && primes[hi]<=x;) {
      sum += primes[hi];
      if (sum == x) {
        cnt++;
        sum -= primes[++lo];
        hi++;
      }
      else if (sum < x) {
        hi++;
      } else {
        while (sum > x) 
          sum -= primes[++lo];
        if (sum == x) { cnt++; sum -= primes[++lo]; }
        hi++;
      }
    } 
    cout << cnt << '\n';
  }
  return 0;
}
