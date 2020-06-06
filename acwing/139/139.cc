/* created   : 2020-06-06 11:23:15
 * accepted  : 2020-06-06 15:31:24
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

struct SnowFlake {
  size_t operator()(const vector<int>& v) const {
    size_t sum = 0;
    const int mod = 1e9 + 7;
    for (auto x : v) {
      (sum += x) %= mod;
    }
    ll mul = 1;
    for (auto x : v) {
      mul = (mul * x) % mod;
    }
    return (sum + mul) % mod;
  }

  bool operator()(const vector<int>& a, const vector<int>& b) const {
    int n = a.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        bool ok = true;
        for (int k = 0; k < n; k++) {
          if (a[(i + k) % 6] != b[(j + k) % 6]) {
            ok = false;
            break;
          }
        }
        if (ok) return true;
        ok = true;
        for (int k = 0; k < n; k++) {
          if (a[(i + k) % 6] != b[(j - k + 6) % 6]) {
            ok = false;
            break;
          }
        }
        if (ok) return true;
      }
    }
    return false;
  }
};

void solve() {
  int n; cin >> n;
  unordered_map<vector<int>, int, SnowFlake, SnowFlake> mp;
  for (int i = 0; i < n; i++) {
    vector<int> x(6);
    for (int j = 0; j < 6; j++) {
      cin >> x[j];
    }
    mp[x]++;
  }
  trace(mp);
  for (auto it : mp) {
    if (it.y >= 2) {
      cout << "Twin snowflakes found.\n";
      return;
    }
  }
  cout << "No two snowflakes are alike.\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
