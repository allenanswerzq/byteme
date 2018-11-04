#include<bits/stdc++.h>using namespace std;

#define ll long long
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

class Solution {
public:
  bool isValid(string ss) {
    if (ss.size() <= 1) return 0;
    deque<char> dq;
    for (int i = 0; i < ss.size(); ++i) {
      if (ss[i] == '(' || ss[i] == '[' || ss[i] == '{')
        dq.push_back(ss[i]);
      else if (ss[i] == ')' || ss[i] == ']' || ss[i] == '}') {
        if (sz(dq) == 0) return 0;
        char c = dq.back();
        if ((c == '(' && ss[i] == ')') || 
            (c == '[' && ss[i] == ']') || 
            (c == '{' && ss[i] == '}'))
          dq.pop_back();
        else
          return 0;
      }
    }

    return sz(dq) ? 0 : 1;
  }
};

void test(string inp) {
  Solution go;
  int r = go.isValid(inp);
  output(1, r);
}

int main() {
  test("()[]{}");
  test("([)]");
  return 0;
}
