#include<bits/stdc++.h>using namespace std;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define pvi(x) fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args> 
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ','); 
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...); 
} 

bool check(string aa) {
  int cnt = 0;
  for (int i = 0; i < aa.size(); ++i) {
    if (aa[i] == '(') ++cnt;
    else if (aa[i] == ')') --cnt;
    if (cnt < 0) return 0;
  }
  return cnt == 0;
}

#define vs vector<string>

class Solution {
public:
  vs removeInvalidParentheses(string aa) {
    vs ret;
    unordered_set<string> visit;
    deque<string> dq;
    dq.push_back(aa);
    visit.insert(aa);
    while (sz(dq)) {
      int n = sz(dq);
      bool ok = 0;
      fori (i, 0, n) {
        auto tmp = dq.front(); dq.pop_front();
        // trace(tmp);
        if (check(tmp)) {
          ret.push_back(tmp); 
          ok = 1;
        } 
        if (ok) continue;
        fori (i, 0, sz(tmp)) {
          if (!(tmp[i] == '(' || tmp[i] == ')')) continue;
          string nxt = tmp.substr(0, i) + tmp.substr(i + 1);  
          if (!visit.count(nxt)) {
            // trace(tmp, nxt);
            visit.insert(nxt);
            dq.push_back(nxt);
          }
        }
      }
      if (ok == 1) return ret;
    }
    return ret;
  }
};

void test(string inp) {
  vs res = removeInvalidParentheses(inp);
  pvi(res);
}

int main() {
  test("()())()");
  test("(a)())()");
  test(")(");
  return 0;
}

