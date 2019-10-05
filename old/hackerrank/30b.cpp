#include<bits/stdc++.h>
using namespace std;

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

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << '\n';
}

template <typename T, typename... Args>
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ',');
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...);
}

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

stack<string> stk;

int main() {
  string ss; cin >> ss;

  tick();
  trace(sz(ss));

  reverse(all(ss));
  // trace(ss);

  trace(tick());

  for (int i = 0; i < sz(ss); ++i) {
    if (ss[i] == '?') {
      string tt; tt += ss[i];
      stk.push(tt);
    } else {
      if (sz(stk) >= 2) {
        string aa = stk.top(); stk.pop();
        string bb = stk.top(); stk.pop();
        string sign; sign += ss[i];
        if (sign == "-") {
          // trace(aa, sign, bb);
          fori (i, 0, sz(bb)) {
            if (bb[i] == '+') bb[i] = '-';
            else if (bb[i] == '-') bb[i] = '+';
          }
          // trace(aa, sign, bb);
        }
        stk.push(aa + sign + bb);
      }
    }

  }

  trace(tick());
  // string op = stk[0];
  // trace(op);

  // vi ret; ret.pb(1);
  // int sum = 1, aa = 0, bb = 1;
  // fori (i, 1, sz(op)) {
  //   if (op[i] == '-') {
  //     --sum; ++aa;
  //     ret.pb(-1);
  //   } else if (op[i] == '+') {
  //     ++sum; ++bb;
  //     ret.pb(1);
  //   }
  // }

  // // pvi(ret, 1);

  // aa = sum > 0 ? aa : bb;
  // int div = abs(sum / aa);
  // int rem = abs(sum % aa);

  // // trace(aa, sum, div, rem);

  // if (sum > 0) {
  //   fori (i, 0, sz(ret)) {
  //     if (ret[i] < 0)
  //       ret[i] -= div;
  //     if (ret[i] < 0 && rem) {
  //       ret[i]--; rem--;
  //     }
  //   }
  // }

  // if (sum < 0) {
  //   fori (i, 0, sz(ret)) {
  //     if (ret[i] > 0)
  //       ret[i] += div;
  //     if (ret[i] > 0 && rem) {
  //       ret[i]++; rem--;
  //     }
  //   }
  // }

  trace(tick());
  // pvi(ret, 1);

  // fora (r, ret) {
  //   output(abs(r));
  // }

  return 0;
}

