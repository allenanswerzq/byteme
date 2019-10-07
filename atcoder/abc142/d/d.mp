#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
long long gcd(long long a, long long b) {
  if (a < b) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
bitset<1000001> bs;
vector<long long> primes;
void sieve() {
  bs.set();
  bs[0] = bs[1] = 0;
  for (long long i = 2; i <= 1000000; ++i) {
    if (bs[i]) {
      primes.push_back(i);
      for (long long j = i * i; j <= 1000000; j += i) bs[j] = 0;
    }
  }
}
int main() {
  sieve();
  long long A, B, ans = 1;
  scanf("%lld %lld", &A, &B);
  A = gcd(A, B);
  for (long long i: primes) {
    if (A % i == 0) ++ans;
    while (A % i == 0) A /= i;
  }
  if (A != 1) ++ans;
  printf("%lld\n", ans);
  return 0;
}
