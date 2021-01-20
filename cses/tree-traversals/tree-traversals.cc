/* created   : 2021-01-20 22:55:01
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

struct Node {
  int v;
  Node* x;
  Node* y;
};

int N;
vector<int> pre;
vector<int> in;
vector<int> post;
Node* root;

Node* build(int a, int b, int c, int d) {
  if (a > b || c > d) return nullptr;
  int r = pre[a];
  int p = -1;
  for (int j = c; j <= d; j++) {
    if (in[j] == r) {
      p = j;
      break;
    }
  }
  assert(p != -1);
  // c-----p------
  int l = p - c;
  auto x = build(a + 1, a + l, c, p - 1);
  auto y = build(a + l + 1, b, p + 1, d);
  return new Node{r, x, y};
}

void dfs(Node* u) {
  if (!u) return;
  dfs(u->x);
  dfs(u->y);
  post.push_back(u->v);
}

void solve() {
  cin >> N;
  pre.resize(N);
  in.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> pre[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> in[i];
  }
  trace(pre, in);
  root = build(0, N - 1, 0, N - 1);
  dfs(root);
  trace(post);
  for (int i = 0; i < N; i++) {
    cout << post[i] << (i == N - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
