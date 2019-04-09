/**
 *    author:  tourist
 *    created: 30.09.2017 20:38:04       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  multiset<int> plus, minus, unused;
  long long ans = 0;
  for (int x : a) {
//    cerr << "before " << x << ":" << endl;
//    cerr << "plus:"; for (int y : plus) cerr << " " << y; cerr << endl;
//    cerr << "minus:"; for (int y : minus) cerr << " " << y; cerr << endl;
//    cerr << "unused:"; for (int y : unused) cerr << " " << y; cerr << endl;
    if (!unused.empty()) {
      int z = *(unused.begin());
      if (x > z) {
        if (!plus.empty() && z > *(plus.begin())) {
        } else {
          plus.insert(x);
          minus.insert(z);
          unused.erase(unused.begin());
          ans += x - z;
          continue;
        }
      }
    }
    if (!plus.empty()) {
      int z = *(plus.begin());
      if (x > z) {
        plus.erase(plus.begin());
        plus.insert(x);
        unused.insert(z);
        ans += x - z;
        continue;
      }
    }
    unused.insert(x);
  }
  cout << ans << endl;
  return 0;
}
