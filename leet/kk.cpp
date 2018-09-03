#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  printf("[ ");
  for (auto x:v)
  printf("%d ", x); 
  printf("]\n");
}

using namespace std;

int gcd ( int a, int b )
{
  if ( a==0 ) return b;
  return gcd ( b%a, a );
}

int func(int n) {
  vector<int> cnt(n+1, 0);
  cnt[0] = 0;
  cnt[1] = 1;
  cnt[2] = 5;
  if (n <= 2) return cnt[n];
  for (int i=3; i<=n; ++i) {
  for (int j=1; j<i; ++j) {
  if (gcd(i, j)==1 && j==1) {cnt[i] += 5; }
  else if( gcd(i, j)==1 && j!=1) {cnt[i] += 2; }
  else if (gcd(i, j) > 1) {
    int x = i / j;
    for (int b=1; b<=n; b++)
    for (int d=1; x*d<=n; d++) {
    if (b == x*d) cnt[i]++;
    }
  }
  }  
  }

  long long  sum = 0;
  for (int i=1; i<=n; ++i)
  sum += cnt[i];
  return sum % 1000000007;
}

int main(int argc, char** argv) {
  for (int i=1; i<=5; i++)
   printf("%d\n", func(i)); 
  return 0;
}
