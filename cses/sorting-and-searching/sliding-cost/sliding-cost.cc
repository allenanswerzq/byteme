/* created   : 2020-11-11 21:26:14
 * accepted  : 2020-11-12 08:52:18
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

multiset<int> bot, top;
ll sb = 0;
ll st = 0;
int N, K;

void insert(int x) {
  bot.insert(x);
  sb += x;
  if (bot.size() > (K - 1) / 2) {
    int y = *bot.rbegin();
    bot.erase(bot.find(y));
    top.insert(y);
    sb -= y, st += y;
  }
}

void erase(int x) {
  auto it = bot.find(x);
  if (it == bot.end()) {
    assert(top.size());
    it = top.find(x);
    assert(it != top.end());
    st -= *it;
    top.erase(it);
  }
  else {
    bot.erase(it);
    sb -= x;
    if (top.size()) {
      int y = *top.begin();
      bot.insert(y);
      top.erase(top.begin());
      st -= y, sb += y;
    }
  }
}

void solve() {
  cin >> N >> K;
  vector<int> A(N);
  for (int& a : A) {
    cin >> a;
  }
  vector<ll> ans;
  for (int i = 0; i < N; i++) {
    insert(A[i]);
    if (i >= K - 1) {
      trace(bot, top, st, sb);
      ll med = *top.begin();
      ll cost = st - med * top.size() + med * bot.size() - sb;
      ans.push_back(cost);
      erase(A[i - K + 1]);
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
