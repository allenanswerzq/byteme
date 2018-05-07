#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <string>
#include <cstdio>
#include <random>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define fora(e, c) for (auto &e : c)
#define all(x) (x).begin(), (x).end()
#define mst(X, v) memset((X), (v), sizeof((X)))
#define len(X) strlen(X)
#define vi vector<int>
#define vs vector<string>
#define sz(x) ((int)(x).size())
#define pii pair<int, int>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define cerr(x) cerr << #x " is " << (x) << endl
const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class RevolvingDoors {
public:
  vs map;
  vector<pii> door;
  int dist[50][50][1<<10];
  int sx, sy, ex, ey;
  int n, m, d;
  bool on_door(int x, int y, int state);
  void bfs(int sx, int sy, int state);
  int turns(vs map);
};

bool RevolvingDoors::on_door(int x, int y, int state) {
  fori(i, 0, d) {
    int dx = door[i].fi, dy = door[i].se;
    if (!(state & (1<<i))) {
      // This door is a horizontal door
      if (x == dx && (y == dy-1 || y == dy+1))
        return true;
    }  else {
      if (y == dy && (x == dx-1 || x == dx+1))
        return true;
    }
  }
  return false;
}

void RevolvingDoors::bfs(int sx, int sy, int state) {
  typedef pair<pii, int> ppi;
  queue<ppi> Q;
  dist[sx][sy][state] = 0;
  Q.push( ppi( pii(sx, sy), state ) );
  vector<vi> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  while (!Q.empty()) {
    ppi top = Q.front(); Q.pop();
    int x = top.fi.fi, y = top.fi.se, st = top.se;

    // In a particular position, we can either move towards four directions or
    fora(d, dirs) {
      int nx = x + d[0], ny = y + d[1];
      // If it exceeds the range of map
      if (! (0<nx && nx<n && 0<ny && ny<m)) continue;
      // If it is a wall or door
      if (map[nx][ny]=='#' || map[nx][ny]=='O') continue;
      // If its adjcent to a door
      if (on_door(nx, ny, st)) continue;
      
      if (dist[nx][ny][st] > dist[x][y][st]) {
        dist[nx][ny][st] = dist[x][y][st];
        Q.push( ppi (pii(nx, ny), st) );
      }
    }

    // we can turn a door's state
    fori(i, 0, d) {
      if (abs(door[i].fi - x) == 1 && abs(door[i].se - y) == 1) {
        // Change ith door's state
        int new_state = st ^ (1<<i);
        if (dist[x][y][new_state] > dist[x][y][st] + 1) {
          dist[x][y][new_state] = dist[x][y][st] + 1;
          Q.push( ppi( pii(x, y), new_state) );
        }
      }
    }
  }
}

int RevolvingDoors::turns(vs map) {
  this->map = map;  
  n = map.size(), m = map[0].size();
  int state = 0;
  fori(i, 0, n)
    fori(j, 0, m) {
      if (map[i][j] == 'S') sx = i, sy = j;
      if (map[i][j] == 'E') ex = i, ey = j;
      if (map[i][j] == 'O') {
        door.pb(mp(i, j));
        // whether this door is a vertical door or horizontal door
        if(map[i+1][j] == '|') state |= (1<<sz(door) - 1);
      }      
    }
  d = door.size();

  mst(dist, 0x30);
  bfs(sx, sy, state);

  int res = INT_MAX;
  fori(st, 0, 1<<d) {
    res = min(res, dist[ex][ey][st]);
  }

  if (res >= INT_MAX) return -1;
  return res;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  return 0;
}
