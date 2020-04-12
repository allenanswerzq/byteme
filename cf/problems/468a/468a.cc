/* created   : 2020-04-12 21:20:22
 * accepted  : 2020-04-12 22:12:12
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  if (n <= 3) {
    printf("NO\n");
  }
  else if (n % 2 == 0) {
    printf("YES\n");
    printf("1 * 2 = 2\n");
    printf("2 * 3 = 6\n");
    printf("6 * 4 = 24\n");
    for (int i = 5; i <= n; i += 2) {
      printf("%d - %d = 1\n", i + 1, i);
      printf("24 * 1 = 24\n");
    }
  }
  else {
    printf("YES\n");
    printf("2 * 4 = 8\n");
    printf("8 + 1 = 9\n");
    printf("3 * 5 = 15\n");
    printf("15 + 9 = 24\n");
    for (int i = 6; i + 1 <= n; i += 2) {
      printf("%d - %d = 1\n", i + 1, i);
      printf("24 * 1 = 24\n");
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
