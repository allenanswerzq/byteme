#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;

const int N = 5555;

char s[N];
int f[N], sum[N];
int last[N];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i < n; i++) {
    f[i] = 0;
  }
  f[0] = 1;
  for (int it = 0; it < n; it++) {
    for (int c = 0; c < 26; c++) {
      last[c] = -1;
    }
    sum[0] = 0;
    for (int i = 0; i < n; i++) {
      sum[i + 1] = sum[i] + f[i];
      if (sum[i + 1] >= md) {
        sum[i + 1] -= md;
      }
    }
    for (int i = 0; i < n; i++) {
      f[i] = sum[i + 1] - sum[last[s[i] - 'a'] + 1];
      if (f[i] < 0) {
        f[i] += md;
      }
      last[s[i] - 'a'] = i;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + f[i]) % md;
  }
  printf("%d\n", ans);
  return 0;
}
