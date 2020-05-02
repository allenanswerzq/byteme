/* created   : 2020-05-02 15:01:48
 * accepted  : 2020-05-02 15:07:09
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

bool is_prime(int x) {
  if (x == 1) return false;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

void solve() {
  int n; cin >> n;
  int next_prime = n;
  while (!is_prime(next_prime)) {
    next_prime++;
  }
  cout << next_prime << "\n";
  for (int i = 0; i < n; i++) {
    cout << i + 1 << " " << (i + 1) % n + 1 << "\n";
  }
  for (int i = n; i < next_prime; i++) {
    int x = i - n + 1;
    cout << x << " " << x + n / 2 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
