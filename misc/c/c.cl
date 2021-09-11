/* created   : 2021-09-11 20:10:01
 * accepted  : 2021-09-11 20:35:02
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

vector<int> read_vector() {
  string ss;
  getline(cin, ss);
  istringstream iss(ss);
  int x;
  vector<int> ans;
  while (iss >> x) {
    ans.push_back(x);
  }
  return ans;
}

void solve() {
  vector<int> A = read_vector();
  vector<int> B = read_vector();
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
