/* created   : 2020-06-21 11:10:18
 * accepted  : 2020-06-21 11:51:18
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 20;
int max_weight;
int cat[N];
int ans;
int n;

void dfs(int id, vector<int>& car) {
  if (id == n + 1) {
    ans = min(ans, (int) car.size());
    return;
  }
  if ((int) car.size() >= ans) return;
  int weight = cat[id];
  for (int i = 0; i < (int) car.size(); i++) {
    if (car[i] + weight <= max_weight) {
      car[i] += weight;
      dfs(id + 1, car);
      car[i] -= weight;
    }
  }
  if (weight <= max_weight) {
    car.push_back(weight);
    dfs(id + 1, car);
    car.pop_back();
  }
}

void solve() {
  cin >> n >> max_weight;
  for (int i = 0; i < n; i++) {
    cin >> cat[i];
  }
  sort(cat, cat + n);
  reverse(cat, cat + n);
  vector<int> car;
  ans = 1e9 + 7;
  dfs(0, car);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
