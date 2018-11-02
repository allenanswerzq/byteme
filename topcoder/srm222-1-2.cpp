#include<bits/stdc++.h>
using namespace std;

class WalkingHome {
public:
  vs map;
  int dist[50][50];
  int r, c, d;
  int sx, sy, hx, hy;
  int fewestCrossings(vs map);
};

int WalkingHome::fewestCrossings(vs mp) {
  map = mp;
  r = sz(map), c = sz(map[0]);
  fori(i, 0, r)
    fori(j, 0, c) {
      if (map[i][j] == 'S') sx = i, sy = j;
      if (map[i][j] == 'H') hx = i, hy = j;
    }

  fori (i, 0, 50) fori (j, 0, 50) {
    dist[i][j] = 0x30303030;
  }

  dist[sx][sy] = 0;

  vector<vi> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
  deque<pii> dq;
  dq.pb(pii(sx, sy));
  map[sx][sy] = map[hx][hy] = '.';
  while (! dq.empty()) {
    pii top = dq.front(); dq.pop_front();
    int x = top.fi, y = top.se;
    // cout << x << ' ' << y << '\n';
    fora(d, dirs) {
      int nx = x + d[0], ny = y + d[1];
      // cout << "new: " << nx << ' ' << ny << '\n';
      if (!(0 <= nx && nx < r && 0 <= ny && ny < c)) continue;
      if (map[nx][ny] == 'F' || map[nx][ny] == '*') continue;
      if (map[nx][ny] == '|') {
        // Just cross over all vertical streets adjcent between each other.
        while (ny < c && map[nx][ny] == '|') ++ny;
        if (ny < c && map[nx][ny] == '.' && dist[nx][ny] > dist[x][y] + 1) {
          dist[nx][ny] = dist[x][y] + 1;
          dq.pb(pii(nx, ny));
        }
      }
      else if (map[nx][ny] == '-') {
        while (nx < r && map[nx][ny] == '-') ++nx;
        if (nx < r && map[nx][ny] == '.' && dist[nx][ny] > dist[x][y] + 1) {
          dist[nx][ny] = dist[x][y] + 1;
          dq.pb(pii(nx, ny));
        }
      } else {
        // Just update minimum value, since no crossing strees happen here.
        if (dist[nx][ny] > dist[x][y]) {
          dist[nx][ny] = dist[x][y];
          dq.pb(pii(nx, ny));
        }
      }
    }
  }
  return dist[hx][hy] == 0x30303030 ? -1 : dist[hx][hy];
}

void test(vs aa) {
  WalkingHome go;
  int r = go.fewestCrossings(aa);
  output(r);
}

int main() {
  test({"S.|..", "..|.H"});
  test({"S.|..", "..|.H", "..|..", "....."});
  test({"S.....", "---*--", "...|..", "...|.H"});
  return 0;
}
