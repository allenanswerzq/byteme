#include <bits/stdc++.h>

using namespace std;

const long long inf = (long long) 1e18;
const int infint = (int) 2e9;

const int N = 1234567;

int c[N];
int mask[N];

multiset <int> s[4];
multiset <int>::iterator it[4];
int ptr[4];
int num[4];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  if (k > m) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", c + i);
    mask[i] = 0;
  }
  for (int t = 0; t < 2; t++) {
    int foo;
    scanf("%d", &foo);
    while (foo--) {
      int bar;
      scanf("%d", &bar);
      bar--;
      mask[bar] |= (1 << t);
    }
  }
  for (int i = 0; i < n; i++) {
    s[mask[i]].insert(c[i]);
  }
  it[3] = s[3].end();
  ptr[3] = s[3].size();
  long long ans = inf;
  long long cur = 0;
  for (int z : s[3]) {
    cur += z;
  }
  for (int j = 0; j < 3; j++) {
    it[j] = s[j].begin();
    ptr[j] = 0;
  }
  for (int both = m; both >= 0; both--) {
    while (ptr[3] > both) {
      it[3]--;
      ptr[3]--;
      cur -= *it[3];
    }
    while (ptr[0] + ptr[1] + ptr[2] < m - both) {
      int best = infint;
      int best_j = -1;
      for (int j = 0; j < 3; j++) {
        num[j] = (it[j] == s[j].end() ? infint : (*it[j]));
        if (num[j] < best) {
          best = num[j];
          best_j = j;
        }
      }
      if (best_j == -1) {
        break;
      }
      cur += best;
      it[best_j]++;
      ptr[best_j]++;
    }
    for (int t = 1; t <= 2; t++) {
      while (ptr[t] < k - both && it[t] != s[t].end()) {
        if (ptr[0] == 0 && ptr[3 - t] <= k - both) {
          break;
        }
        auto it0 = it[0];
        auto it3t = it[3 - t];
        if (ptr[3 - t] <= k - both || (ptr[0] != 0 && *--it0 > *--it3t)) {
          it[0]--;
          ptr[0]--;
          cur -= *it[0];
        } else {
          it[3 - t]--;
          ptr[3 - t]--;
          cur -= *it[3 - t];
        }
        cur += *it[t];
        it[t]++;
        ptr[t]++;
      }
    }
    if (ptr[3] == both && ptr[1] + ptr[3] >= k && ptr[2] + ptr[3] >= k && ptr[0] + ptr[1] + ptr[2] + ptr[3] == m) {
      ans = min(ans, cur);
    }
  }
  cout << (ans == inf ? -1LL : ans) << endl;
  return 0;
}
