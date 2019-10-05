//============================================================================
// Name        : 799a
// Date        : Sun Apr 21 20:33:01 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;

void solve() {
  int n, t, k, d;
  cin >> n >> t >> k >> d;
  // How much time in total if only one oven doing his work.
  int tot = (n + k - 1) / k * t;
  // Assume we finished work at time `tot - 1`, compute how many
  // goods we can produce for two ovens..
  // The first oven.
  int both = (tot - 1) / t * k;
  if (tot - 1 - d > 0) {
  // The second oven.
    both += (tot - 1 - d) / t * k;
  }
  cout << (both >= n ? "YES" : "NO") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
