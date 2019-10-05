#include<bits/stdc++.h>
using namespace std;

class WordFind {
public:
  vs wl;
  vs grid;
  vs findWords(vs aa, vs bb) {
    grid = aa;
    wl = bb;
    int n = sz(grid), m=sz(grid[0]), d=sz(wl);
    vs res;
    fori (i, 0, d) {
      string w = wl[i];
      fori (k, 0, n) {
        int flag = 0;
        fori (j, 0, m) {
          if (grid[k][j] == w[0]) {
            fori(h, 0, 3) {
              int r = 0;
              // Go right
              if (h == 0)
                while (r + j < m && grid[k][r + j] == w[r]) ++r;
              // Go down
              if (h == 1)
                while (k + r < n && grid[k + r][j] == w[r]) ++r;
              // Go down and right
              if (h == 2)
                while (k + r < n && grid[k + r][j+r] == w[r]) ++r;
              if (r == sz(w)) {
                res.pb(to_string(k) + " " + to_string(j));
                flag = 1;
                break;
              }
            }
            if (flag) break;
          }
        }
        if (flag) break;
      }
    }
    return res;
  }
};

void test(vs aa, vs bb) {
  WordFind go;
  auto ret = go.findWords(aa, bb);
  pvi(ret, 1);
}

int main() {
  test({"TEST", "GOAT", "BOAT"}, {"GOAT", "BOAT", "TEST"});

  test({"EASYTOFINDEAGSRVHOTCJYG",
        "FLVENKDHCESOXXXXFAGJKEO",
        "YHEDYNAIRQGIZECGXQLKDBI",
        "DEIJFKABAQSIHSNDLOMYJIN",
        "CKXINIMMNGRNSNRGIWQLWOG",
        "VOFQDROQGCWDKOUYRAFUCDO",
        "PFLXWTYKOITSURQJGEGSPGG"},
      {"EASYTOFIND", "DIAG", "GOING", "THISISTOOLONGTOFITINTHISPUZZLE"});
  return 0;
}
