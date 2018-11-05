// #include <bits/stdc++.h>
#include <deque>
#include <vector>
#include <cassert>
#include <cstring>
#include <iostream>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define pend cout << '\n'
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(v) cout << (v) << '\n'
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if(v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

// #define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
// template <typename T>
// void _f(const char* name, T&& arg) {
//   cout << fixed << name << ": " << arg << '\n';
// }

// template <typename T, typename... Args>
// void _f(const char* names, T&& arg, Args&&... args) {
//   const char* split = strchr(names + 1, ',');
//   cout.write(names, split - names) << ": " << arg << " |";
//   _f(split, args...);
// }

// double tick() {
//   static clock_t old;
//   clock_t now = clock();
//   double diff = 1.0 * (now - old);
//   diff /= CLOCKS_PER_SEC;
//   old = now;
//   return diff;
// }

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int va, vb, c;

struct Stat {
  int a, b, k, ta, tb;
  int op;
  Stat *pre;
  Stat() : a(0), b(0), pre(NULL) {
    ta = a; tb = b; op = -1; k = 0;
  };

  Stat(int a, int b, Stat* pre = NULL): a(a), b(b), pre(pre) {
    ta = a; tb = b; op = -1; k = 0;
  };

  void reset() {
    a = ta; b = tb; op = -1; k = 0;
  }

  void fill(int i) {
    k = i, op = 0;
    if (i == 1) a = va;
    if (i == 2) b = vb; 
  }

  void pour(int i) {
    k = i, op = 1;
    if (i == 1) {
      // 1 --> 2
      if (a <= 0) return;
      int d = max(vb - b, 0);
      b = min(b + a, vb);
      a = a >= d ? a - d : 0;
    }

    if (i == 2) {
      if (b <= 0) return;
      int d = max(va - a, 0);
      a = min(a + b, va);
      b = b >= d ? b - d : 0;
    }

  }

  void drop(int i) {
    k = i, op = 2;
    if (i == 1) a = 0;
    if (i == 2) b = 0;
  }

  string to_string() {
    string r = "";
    if (op == 0) r += "FILL";
    if (op == 1) r += "POUR";
    if (op == 2) r += "DROP";

    if (op == 1) r += (k == 1) ? "(1,2)" : "(2,1)";
    else r += (k == 1) ? "(1)" : "(2)";

    return r;
  }

};

void test_fill() {
  // Volume of the two pots respectively.
  va = 3, vb = 5;
  Stat st;
  assert(st.op == -1 && !st.pre);
  assert(st.a == 0 && st.b == 0);
  st.fill(1);
  assert(st.a == 3 && st.b == 0);
  st.reset(); st.fill(2);
  assert(st.a == 0 && st.b == 5);
  st.reset(); st.fill(1); st.fill(2);
  assert(st.a == 3 && st.b == 5);
} 

void test_pour() {
  va = 3, vb = 5;
  Stat st(2, 1);
  // 1 --> 2
  st.pour(1);
  assert(st.a == 0 && st.b == 3); 
  // 2 --> 1
  st.reset(); st.pour(2);
  assert(st.a == 3 && st.b == 0);

  Stat st2(2, 5);
  st2.pour(1);
  assert(st2.a == 2 && st2.b == 5);
  st2.reset(); st2.pour(2);
  assert(st2.a == 3 && st2.b == 4);
  st2.reset(); st2.pour(1); st2.pour(2);
  assert(st2.a == 3 && st2.b == 4);

  Stat st3(3, 5);
  st3.pour(1);
  assert(st3.a == 3 && st3.b == 5);
  st3.pour(2);
  assert(st3.a == 3 && st3.b == 5);
}


void test_drop() {

}

void test_all() {
  test_fill();
  test_pour();
  test_drop();
}

void path(Stat *cur) {
  string ret = "";
  while (cur->pre) {
    ret = cur->to_string() + "\n" + ret; 
    cur = cur->pre;
  } 
  output(ret.substr(0, sz(ret)-1));
}

int visit[100 * 100 + 10];

void solve() {
  cin >> va >> vb >> c;

  mst(visit, 0);
  deque<Stat*> dq;
  dq.clear();
  Stat *st = new Stat();
  dq.pb(st);
  visit[0] = 1;

  int level = 0;
  while (sz(dq)) {
    int l = sz(dq);
    fori (i, 0, l) {
      Stat* cur = dq.front(); dq.pop_front();

      // trace(cur->a, cur->b, cur->op);
      if (cur->a == c || cur->b == c) {
        output(level);
        path(cur); 
        return;
      }

      fori (j, 0, 3) {
        fori (k, 1, 3) {
          Stat *nxt = new Stat(cur->a, cur->b, cur);
          if (j == 0) nxt->fill(k);
          if (j == 1) nxt->pour(k); 
          if (j == 2) nxt->drop(k);
          int st = nxt->a * 100 + nxt->b;
          // trace(nxt->a, nxt->b, nxt->op, nxt->k);
          if (!visit[st]) {
            visit[st] = 1;
            dq.pb(nxt);
          }
        }

      }
    }
    ++level;
  }

  output("impossible");

}

int main() {
  // test_all();
  solve();
  return 0;
}

