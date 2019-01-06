#include <bits/stdc++.h>
using namespace std;

int eucliden(int x, int y) {
  return x * x + y * y;
}

vvi dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
public:
  int robotSim(vector<int>& aa, vector<vector<int>>& bb) {
    unordered_set<pii> obs;
    fora (b, bb) obs.insert({b[0], b[1]});

    int dir, x, y;
    x = y = dir = 0;
    int res = 0;
    fora (it, aa) {
      if (it == -2) {
        dir = (dir + 3) % 4;
      } else if (it == -1) {
        dir = (dir + 1) % 4;
      } else {
        fori (k, 0, it) {
          int nx = x + dirs[dir][0];
          int ny = y + dirs[dir][1];
          if (obs.cout({nx, ny})) break;
          x = nx; y = ny;
        }
      }
      res = max(res, eucliden(x, y));
    }
    return res;
  }
};

int main() {
  return 0;
}
