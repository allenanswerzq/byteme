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

//     1        2        3    ...
//    /\        /\       /\
// 10 ...19  20...29  30...39   ....

#define vi vector<int>
#define vvi vector<vi>

vi ret;
void dfs(int cur, int goal) {
  if (cur > goal) return;
  else {
    ret.push_back(cur);
    fori (i, 1, 10) {
      if (cur * 10 + i > goal) return;
      dfs(cur * 10 + i, goal);
    } 
  }
}

class Solution {
public:
  vi lexicalOrder(int goal) {
    fori (i, 1, 11) {
      dfs(i, goal); 
    }
    return ret;
  } 
}

int main() {
  return 0;
}
