#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

  vector<int> p({4, 8, 15, 16, 23, 42});

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] = lower_bound(p.begin(), p.end(), a[i]) - p.begin();
  }

  vector<int> seq(6);
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      ++seq[0];
    } else {
      if (seq[a[i] - 1] > 0) {
        --seq[a[i] - 1];
        ++seq[a[i]];
      }
    }
  }
  trace(seq);
  cout << n - seq[5] * 6 << endl;

  return 0;
}
