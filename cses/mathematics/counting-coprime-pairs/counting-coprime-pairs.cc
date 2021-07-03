/* created   : 2021-06-27 17:11:38
 * accepted  : 2021-07-03 18:53:24
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<ll, 2>;

template <int N>
vector<int> mobius() {
  vector<int> pr;
  vector<int> lp(N);
  vector<int> ans(N);
  ans[1] = 1;
  for (int i = 2; i < N; i++) {
    if (lp[i] == 0) {
      // This number is a prime number.
      lp[i] = i;
      pr.push_back(i);
      // Set to -1 as it only has odd number of primes
      ans[i] = -1;
    }
    for (int j = 0; j < (int) pr.size() && pr[j] <= lp[i] && i * pr[j] < N; j++) {
      int k = i * pr[j];
      assert(k < N);
      lp[k] = pr[j];
      if (pr[j] == lp[i]) {
        // i * pr[j] will have square primes
        ans[k] = 0;
      }
      else {
        ans[k] = -ans[i];
      }
    }
  }
  return ans;
}

const int Z = 1e6 + 7;

// The number of ways chose 2 from n
ll cnk(ll n) { return n * (n - 1) / 2; }

void solve_mobius() {
  int N; cin >> N;
  vector<int> cnt(Z);
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    cnt[x]++;
  }
  vector<int> mu = mobius<Z>();
  ll ans = 0;
  // From all paris minus the pairs that has gcd equal 2,3,4...
  for (int i = 1; i < Z; i++) {
    // Compute how many numbers can be divided by `i`
    ll tot = 0;
    for (int j = i; j < Z; j += i) {
      tot += cnt[j];
    }
    // Inclusion-exclusion
    // trace(i, mu[i], tot, cnk(tot));
    ans += cnk(tot) * mu[i];
  }
  cout << ans << "\n";
}

void solve() {
  int N; cin >> N;
  vector<int> cnt(Z);
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    cnt[x]++;
  }
  // The number of pairs that has gcd exactly equal `i`
  vector<ll> f(Z);
  for (int i = 1; i < Z; i++) {
    ll tot = 0;
    for (int j = i; j < Z; j += i) {
      tot += cnt[j];
    }
    // Now f[i] is the number of pairs theirs gcd is `i`, but not exactly
    // Their gcd colud be i, 2*i, 3*i, 4*i
    f[i] = cnk(tot);
  }
  trace(mt(f, 20));
  for (int i = Z - 1; i >= 1; i--) {
    // Make gcd for i exact by removing others
    for (int j = i + i; j < Z; j += i) {
      f[i] -= f[j];
    }
  }
  cout << f[1] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
