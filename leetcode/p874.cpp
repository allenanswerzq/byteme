#include<bits/stdc++.h>
using namespace std;

int eucliden(int x, int y) {
  return x * x + y * y;
}

const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
public:
  int robotSim(vector<int>& aa, vector<vector<int>>& bb) {
  uset<pii> obs;
  fora (b, bb) {
    obs.insert({b[0], b[1]});
  }
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
 
  Solution go;
  vi aa = {4,-1,4,-2,4}; 
  vvi bb = {{2, 4}};
  // vi aa = {4, -1, 3}; 
  // vvi bb = {};
  // vi aa = {-2,-1,8,9,6};
  // vvi bb = {{-1,3},{0,1},{-1,5},{-2,-4},{5,4},{-2,-3},{5,-1},{1,-1},{5,5},{5,2}};
  cout << go.robotSim(aa, bb) << endl;
  return 0;
}
