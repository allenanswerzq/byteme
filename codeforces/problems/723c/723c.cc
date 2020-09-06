/* created   : 2020-09-06 19:24:08
 * accepted  : 2020-09-06 19:49:29
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N, M; cin >> N >> M;
  vector<int> A(N);
  unordered_map<int, int> cnt;
  for (auto& a : A) {
    cin >> a;
    cnt[a]++;
  }
  int num = N / M;
  vector<int> st;
  for (int i = 1; i <= M; i++) {
    if (cnt[i] < num) {
      st.push_back(i);
    }
  }
  int lo = 0;
  int change = 0;
  for (int x : st) {
    int i = lo;
    for (; i < N && cnt[x] < num; i++) {
      if ((1 <= A[i] && A[i] <= M && cnt[A[i]] > num) || (A[i] > M)) {
        cnt[A[i]]--;
        A[i] = x;
        cnt[x]++;
        change++;
      }
    }
    assert(cnt[x] == num);
    lo = i;
  }
  cout << num << " " << change << "\n";
  for (int i = 0; i < N; i++) {
    cout << A[i] << (i == N - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
