#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
	ll n, k; cin >> n >> k;
	if (k >= 43) {
		cout << "No\n";
		return;
	}
	set<int> st;
	for (int i = 1; i <= k; i++) {
		int x = n % i;
		if (st.count(x)) {
			cout << "No\n";
			return;
		}
		st.insert(x);
	}	
	cout << "Yes\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
