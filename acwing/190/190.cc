/* created   : 2020-06-27 18:23:45
 * accepted  : 2020-06-27 21:04:32
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 7;
string a[N], b[N];
string s, t;
int n;

int extend(deque<string>& qu, unordered_map<string, int>& ma,
           unordered_map<string, int>& mb, string a[], string b[]) {
  int m = qu.size();
  for (int i = 0; i < m; i++) {
    string cur = qu.front(); qu.pop_front();
    for (int j = 0; j < (int) cur.size(); j++) {
      for (int k = 0; k < n; k++) {
        if (cur.substr(j, a[k].size()) == a[k]) {
          string tmp = cur.substr(0, j) + b[k] + cur.substr(j + a[k].size());
          if (ma.count(tmp)) continue;
          if (mb.count(tmp)) return ma[cur] + mb[tmp] + 1;
          ma[tmp] = ma[cur] + 1;
          qu.push_back(tmp);
        }
      }
    }
  }
  return 11;
}

void solve() {
  cin >> s >> t;
  while (cin >> a[n] >> b[n]) {
    n++;
  }
  deque<string> qa, qb;
  unordered_map<string, int> ma, mb;
  qa.push_back(s);
  qb.push_back(t);
  ma[s] = 0;
  mb[t] = 0;
  trace(qa, qb, ma, mb, n);
  while (qa.size() && qb.size()) {
    int step = -1;
    if (qa.size() <= qb.size()) {
      step = extend(qa, ma, mb, a, b);
    }
    else {
      step = extend(qb, mb, ma, b, a);
    }
    trace(qa, qb, step);
    if (step <= 10) {
      cout << step << "\n";
      return;
    }
  }
  cout << "NO ANSWER!\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
