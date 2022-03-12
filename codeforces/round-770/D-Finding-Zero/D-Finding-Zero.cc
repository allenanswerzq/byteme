/* created   : 2022-03-12 17:09:59
 * accepted  : 2022-03-12 23:16:21
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

int query(int i, int j, int k) {
  cout << "? " << i << " " << j << " " << k << endl;
  int x; cin >> x;
  return x;
}

ar send(const vector<int>& idx) {
  assert(idx.size() == 4);
  vector<ar> tmp;
  for (int i = 0; i < 4; i++) {
    vector<int> pos;
    for (int p : idx) {
      if (p != idx[i]) {
        pos.push_back(p);
      }
    }
    int x = query(pos[0], pos[1], pos[2]);
    trace(i, idx, x, pos);
    tmp.push_back({x, idx[i]});
  }
  sort(all(tmp));
  trace(tmp);
  // return the middle value positions among 4 numbers
  return {tmp[3][1], tmp[2][1]};
}

void solve() {
  // 1 2 0 3
  // 1: 3-0=3
  // 2: 3-0=3
  // 0: 3-1=2
  // 3: 2-1=1
  //
  // 1 4 6 9 0 8 9 n=7
  // 1: 9-4 = 5
  // 4: 9-1 = 8 x
  // 6: 9-1 = 8 x
  // 9: 6-1 = 5
  //
  // ((n - 4) + 1) / 2 * 4 + 4
  // (n - 3) * 2 + 4 = 2n - 2
  int N; cin >> N;
  set<int> st = {1, 2};
  int p = 3;
  while (p <= N) {
    st.insert(p);
    if (p + 1 > N) {
      // N is even, we pick any number that already ignored before
      for (int i = 1; i <= N; i++) {
        if (!st.count(i)) {
          st.insert(i);
          break;
        }
      }
    }
    else {
      st.insert(p + 1);
    }
    vector<int> pos{st.begin(), st.end()};
    auto middle = send(pos);
    // erase the middle value, keep the max and min, 0 must be the
    // min for the whole array
    for (int m : middle) {
      st.erase(m);
    }
    trace(pos, st);
    p += 2;
  }
  trace(st);
  vector<int> ans{st.begin(), st.end()};
  assert(ans.size() == 2);
  cout << "! " << ans[0] << " " << ans[1] << endl;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
