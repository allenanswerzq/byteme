/* created   : 2020-06-12 23:17:31
 * accepted  : 2020-06-13 07:13:55
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ull unsigned long long

const int N = 1e6 + 7;
const int base = 131;
ull hsh[1100][1100];
ull mul[N];
int n, m, a, b;

ull get(ull arr[], int l, int r) {
  assert(0 <= l && l < m);
  assert(0 <= r && r < m);
  return arr[r + 1] - arr[l] * mul[r - l + 1];
}

void solve() {
  cin >> n >> m >> a >> b;
  mul[0] = 1;
  for (int i = 1; i <= n * m; i++) {
    mul[i] = mul[i - 1] * base;
  }
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    for (int j = 0; j < m; j++) {
      hsh[i][j + 1] = hsh[i][j] * base + s[j] - '0';
    }
  }
  int q; cin >> q;
  set<ull> st;
  vector<ull> queries;
  while (q--) {
    ull val = 0;
    for (int i = 0; i < a; i++) {
      string t; cin >> t;
      trace(i, t);
      for (int j = 0; j < b; j++) {
        val = val * base + t[j] - '0';
      }
    }
    st.insert(val);
    queries.push_back(val);
  }
  for (int j = 0; j + b <= m; j++) {
    int l = j, r = j + b - 1;
    ull val = 0;
    for (int i = 0; i < n; i++) {
      val = val * mul[b] + get(hsh[i], l, r);
      if (i >= a) {
        val -= get(hsh[i - a], l, r) * mul[a * b];
      }
      if (i >= a - 1) {
        st.erase(val);
      }
    }
  }
  for (auto t : queries) {
    if (st.count(t)) {
      cout << 0 << "\n";
    }
    else {
      cout << 1 << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
