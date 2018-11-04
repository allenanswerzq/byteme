#include<bits/stdc++.h>
using namespace std;

// best approach for this problem
int smallestFactorization(int a) {
  if (a == 1) return 1;
  string s = "";
  for (int i=9; i>=2; --i)
    while (a%i == 0) {
      a /= i;
      s += char('0' + i);
    }    
  if(a > 1) return 0; // cant be divided all
  // NOTE: string to long long
  // res = res*10 + A[i]  
  long long res = stoll(string(s.rbegin(), s.rend()));
  return res <= INT_MAX ? res : 0;
}

int main() {
  return 0;
}
