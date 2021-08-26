/* created   : 2021-08-20 07:37:33
 * accepted  : 2021-08-22 12:31:10
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

bool check(const vector<int>& A) {
  int n = A.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if ((A[i] <= A[j] && A[j] <= A[k]) ||
            (A[i] >= A[j] && A[j] >= A[k])) {
          return false;
        }
      }
    }
  }
  return true;
}

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      int len = j - i + 1;
      if (len >= 5) {
        // subarray has length greater than 5 is always bad.
        break;
      }
      else if (len >= 3) {
        // check whether subarry [i...j] is good.
        vector<int> t(A.begin() + i, A.begin() + j + 1);
        ans += check(t);
      }
      else {
        ans++;
      }
    }
  }
  cout << ans << "\n";
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
