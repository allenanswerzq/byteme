/* created   : 2021-01-09 16:16:09
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

int encode(const string& s) {
  int ans = 0;
  for (int i = 0; i < 9; i++) {
    ans = ans * 10 + s[i] - '0';
  }
  return ans;
}

int swap(const vector<int>& power10, const pair<int, int>& p, int u) {
  int px = p.first, py = p.second;
  //   | |
  // 123456
  int x = u / power10[px] % 10;
  int y = u / power10[py] % 10;
  u -= x * power10[px];
  u -= y * power10[py];
  u += x * power10[py];
  u += y * power10[px];
  return u;
}

void solve() {
  string S;
  for (int i = 0; i < 9; i++) {
    char c; cin >> c;
    S += c;
  }
  vector<pair<int, int>> pos;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      // swap(a --> b) horontional
      pos.push_back({3 * i + j, 3 * i + j + 1});
      // swap(a --> b) vertical
      pos.push_back({3 * j + i, 3 * (j + 1) + i});
    }
  }
  vector<int> power10(10);
  power10[0] = 1;
  for (int i = 1; i < 10; i++) {
    power10[i] = power10[i - 1] * 10;
  }
  int e = encode("123456789");
  trace(power10, e);
  unordered_map<int, int> dist;
  deque<int> qu;
  dist[encode(S)] = 0;
  qu.push_back(encode(S));
  while (qu.size()) {
    int u = qu.front();
    qu.pop_front();
    if (u == e) {
      break;
    }
    for (auto& p : pos) {
      int t = swap(power10, p, u);
      if (!dist[t]) {
        dist[t] = dist[u] + 1;
        qu.push_back(t);
      }
    }
  }
  cout << dist[e] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
