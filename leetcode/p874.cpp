#include<bits/stdc++.h>
using namespace std;




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

const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

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


int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p874-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();

  Solution go;
  vi aa = {4,-1,4,-2,4}; 
  vvi bb = {{2, 4}};
  // vi aa = {4, -1, 3}; 
  // vvi bb = {};
  // vi aa = {-2,-1,8,9,6};
  // vvi bb = {{-1,3},{0,1},{-1,5},{-2,-4},{5,4},{-2,-3},{5,-1},{1,-1},{5,5},{5,2}};
  cout << go.robotSim(aa, bb) << endl;

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
