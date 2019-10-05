//============================================================================
// Name        : 56a
// Date        : Wed May 29 13:58:12 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
  set<string> st = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM",
                    "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
  int n;
  cin >> n;
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    if (isdigit(x[0])) {
      if (stoi(x) < 18) {
        ret++;
      }
    } else {
      if (st.count(x)) {
        ret++;
      }
    }
  }
  cout << ret << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
