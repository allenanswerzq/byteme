#include <vector>
#include <iostream>
#include <cstring>
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

string cube;
int path[10];

/**************************************
         0  1  2
         3  4  5
         6  7  8
 9 10 11 12 13 14 15 16 17 18 19 20
21 22 23 24 25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40 41 42 43 44
         45 46 47
         48 49 50
         51 52 53
****************************************/

const int cell[6][9] = {
  {4,0,1,2,3,5,6,7,8},
  {22,9,10,11,21,23,33,34,35},
  {25,12,13,14,24,26,36,37,38},
  {28,15,16,17,27,29,39,40,41},
  {31,18,19,20,30,32,42,43,44},
  {49,45,46,47,48,50,51,52,53}
};

// Each face has two choices: clock-wise and counterclockwise rotation
const int change[12][20]={
   {11,23,35,34,33,21, 9,10,51,48,45,36,24,12, 6, 3, 0,20,32,44},
   { 9,10,11,23,35,34,33,21,36,24,12, 6, 3, 0,20,32,44,51,48,45},

   // Counter clock-wise: 14->12 13->24 26->13 ...
   // Clock wise: 12->14 24->13 ...
   {14,13,26,38,37,36,24,12,45,46,47,39,27,15, 8, 7, 6,11,23,35},
   {12,24,13,14,26,38,37,36,39,27,15, 8, 7, 6,11,23,35,45,46,47},

   {17,29,41,40,39,27,15,16,47,50,53,42,30,18, 2, 5, 8,14,26,38},
   {15,16,17,29,41,40,39,27,42,30,18, 2, 5, 8,14,26,38,47,50,53},

   {18,19,20,32,44,43,42,30,53,52,51,33,21, 9, 0, 1, 2,17,29,41},
   {42,30,18,19,20,32,44,43,33,21, 9, 0, 1, 2,17,29,41,53,52,51},

   { 0, 1, 2, 5, 8, 7, 6, 3,12,13,14,15,16,17,18,19,20, 9,10,11},
   { 6, 3, 0, 1, 2, 5, 8, 7,15,16,17,18,19,20, 9,10,11,12,13,14},

   {45,46,47,50,53,52,51,48,44,43,42,41,40,39,38,37,36,35,34,33},
   {51,48,45,46,47,50,53,52,41,40,39,38,37,36,35,34,33,44,43,42}
};

bool win(string& cube) {
  fori (i, 0, 6) fori (j, 1, 9) {
    if (cube[cell[i][j]] != cube[cell[i][0]]) {
      return 0;
    }
  }
  return 1;
}

void rotate(string& cube, int face) {
  string tmp = cube;
  fori (i, 0, 20) {
    tmp[change[face][i]] = cube[change[face ^ 1][i]];
  }
  cube = tmp;
}

bool dfs(int cnt, string& cube) {
  // trace(cnt, cube);
  if (cnt <= 0) {
    return win(cube);
  }

  string tmp = cube;
  fori (i, 0, 12) {
    rotate(cube, i);
    path[cnt] = i;
    if (dfs(cnt - 1, cube)) {
      return 1;
    }
    cube = tmp;
  }
  return 0;
}

void solve() {
  cube.resize(54);
  fori (i, 0, 54) {
    cin >> cube[i];
  }

  fori (step, 0, 7) {
    if (step == 6) {
      output(-1);
      return;
    } else {
      if (dfs(step, cube)) {
        output(step);
        ford (j, step, 0) {
          // 1 means clock-wise and -1 means counter clock-wise.
          cout << path[j] / 2 << " " << (path[j] & 1 ? -1 : 1) << '\n';
        }
        return;
      }
    }
  }

}

int main(){
    int t; cin >> t;
    fori (i, 0, t) {
      solve();
    }
    return 0;
}
