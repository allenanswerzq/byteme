/* created   : 2020-07-01 08:16:40
 * accepted  : 2020-07-01 09:02:03
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

template <int N>
bitset<N> sieve() {
  bitset<N> bs;
  bs.set();
  bs[0] = 0;
  bs[1] = 0;
  for (int i = 2; i < N; i++) {
    if (bs.test(i)) {
      for (int j = i + i; j < N; j += i) {
        bs.reset(j);
      }
    }
  }
  return bs;
}

template <int N>
vector<int> get_prime() {
  vector<int> prime;
  auto bs = sieve<N>();
  for (int i = 1; i < N; i++) {
    if (bs.test(i)) {
      prime.push_back(i);
    }
  }
  return prime;
}

vector<int> prime;
ll l, r;

void solve() {
  vector<bool> a(r - l + 1);
  for (auto p : prime) {
    if ((ll) p * p > r) break;
    for (ll k = (l + p - 1) / p; k <= r / p; ++k) {
      if (k > 1) {
        a[k * p - l] = true;
      }
    }
  }
  if (l == 1) a[0] = true;
  // trace(a);
  const int INF = 1e9 + 7;
  int last = -1;
  int mi = INF;
  int mx = 0;
  pair<int, int> ans_mi;
  pair<int, int> ans_mx;
  for (int i = 0; i < a.size(); i++) {
    if (a[i]) continue;
    if (last == -1) {
      last = i;
    }
    else {
      if (i - last + 1 < mi) {
        mi = i - last + 1;
        ans_mi = {l + last, l + i};
      }
      if (i - last + 1 > mx) {
        mx = i - last + 1;
        ans_mx = {l + last, l + i};
      }
      last = i;
    }
  }
  if (mi == INF) {
    cout << "There are no adjacent primes.\n";
  }
  else {
    cout << ans_mi.x << "," << ans_mi.y << " are closest, ";
    cout << ans_mx.x << "," << ans_mx.y << " are most distant.\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prime = get_prime<(int)5e5>();
  while (cin >> l >> r) {
    solve();
  }
  return 0;
}
