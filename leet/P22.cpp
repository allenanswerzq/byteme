#include<bits/stdc++.h>
using namespace std;

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

#define vs vector<string>

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    if (n == 0) return {""};
    vs res;
    fori (i, 0, n) {
      fora (left, generateParenthesis(i))
        fora (right, generateParenthesis(n - 1 - i))
          res.push_back("(" + left + ")" + right);
    }
    return res;
  }
};

void test(int x) {
  Solution go;
  vs res = go.generateParenthesis(x);
  pvi(res);
}

int main(int argc, char **argv) {
  test(3);
  test(4);
  return 0;
}

