#include<bits/stdc++.h>
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

// You are playing the following Flip Game with your friend: 
// Given a string that contains only these two characters: + and -, 
// you and your friend take turns to flip twoconsecutive "++" into "--". 
// The game ends when a person can no longer make a move 
// and therefore the other person will be the winner.
// Write a function to determine if the starting player can guarantee a win.

// For example, given s = "++++", return true. 
// The starting player can guarantee a win by flipping the middle "++" to become "+--+".

// Follow up:
// Derive your algorithm's runtime complexity.

// #define LOCAL_FILE

class Solution {
public:
  bool canWin(string aa) {
    fori (i, 0, sz(aa) - 1) {
      if (aa[i] == '+' && aa[i + 1] == '+') {
        string tmp = aa.substr(0, i) + "--" + aa.substr(i + 2);
        // If the other person will lose.
        if (! canWin(tmp))
          return 1;
      }
    }
    return 0;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

#ifdef LOCAL_FILE
  freopen("p294-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();
#endif 

  Solution go;
  int r = go.canWin("++++");
  output(1, r);

#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
#endif

  return 0;
}
