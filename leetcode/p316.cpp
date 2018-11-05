#include <bits/stdc++.h>
using namespace std;

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

// #define LOCAL_FILE

class Solution {
public:
  string removeDuplicateLetters(string inp) {
    int dp[256]; mst(dp, 0);
    int visit[256]; mst(visit, 0);
    string res = "0";
    fora (ch, inp) dp[ch]++;
    fora (ch, inp) {
      --dp[ch];
      if (visit[ch]) continue;
      while (ch < res.back() && dp[res.back()]) {
        visit[res.back()] = 0;
        res.pop_back();
      }
      res += ch;
      visit[ch] = 1;
    }
    return res.substr(1);
  }
};

void test(string inp, string right) {
  Solution go;
  string res = go.removeDuplicateLetters(inp);
  trace(res, right);
  assert(res == right);
}

int main() {

  test("bcabc", "abd");
  test("cbacdcbc", "acdb");

  return 0;
}
