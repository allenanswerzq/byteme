#include <bits/stdc++.h>
using namespace std;

//  sum[i] denotes total sum from aa[0] to aa[i-1]
int pivotIndex(vi& aa) {
  int n = aa.size();
  vi sum(n, 0);

  for (int i= 0; i < n; ++i) sum[i + 1] = sum[i] + aa[i];

  for (int i = 0; i < n; ++i) {
    if (sum[i] == sum[n] - sum[i+1]) return i;
  }
  return -1;
}

int pivotIndex(vector<int>& aa) {
  int n = aa.size();
  vi a(n + 1, 0), b(n + 1, 0);
  for (int i = 0; i < n; ++i) a[i + 1] = a[i] + aa[i];

  for (int i = n - 2; i >= 0; --i) b[i] = b[i+1] + aa[i+1];

  for (int i = 0; i <= n; ++i)
    if (a[i] == b[i]) return i;

  return -1;
}

int main() {
  return 0;
}
