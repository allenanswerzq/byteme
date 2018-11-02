#include<bits/stdc++.h>
using namespace std;

// Flood fill
class grafixMask {
public:
  int visit[410][610];
  vi sortedAreas(vs rects) {
    int n = sz(rects);
    mst(visit, 0);
    fora (rect, rects) {
      istringstream iss(rect);
      int a, b, c, d;
      iss >> a >> b >> c >> d;
      fori (i, a, c + 1)
        fori (j, b, d + 1)
          visit[i][j] = 1;
    }

    vi res;
    vector<vi> dirs = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
    fori (i, 0, 400) {
      fori (j, 0, 600) {
        // If <i,j> is ntt visited compute the area that can be reached
        int area = 0;
        if (!visit[i][j]) {
          deque<pii> dq;
          dq.pb(pii(i, j));
          while (!dq.empty()) {
            area += 1;
            pii top = dq.front(); dq.pop_front();
            int x = top.first, y = top.second;
            fora (d, dirs) {
              int nx = x + d[0], ny = y + d[1];
              if (!(0 <= nx && nx < 400 && 0 <= ny && ny < 600)) continue;
              if (visit[nx][ny]) continue;
              visit[nx][ny] = 1;
              dq.pb(pii(nx, ny));
            }
          }
        }
        if (area > 0)
          res.pb(area - 1);
      }
    }
    sort(all(res));
    return res;
  }
};

void test(vs aa) {
  grafixMask go;
  vi ret = go.sortedAreas(aa)
  pvi(ret, 1);
}

int main() {
  test({"0 292 399 307"});
  test({"48 192 351 207", "48 392 351 407",
        "120 52 135 547", "260 52 275 547"});

  test({"0 20 399 20", "0 44 399 44", "0 68 399 68", "0 92 399 92",
        "0 116 399 116", "0 140 399 140", "0 164 399 164", "0 188 399 188",
        "0 212 399 212", "0 236 399 236", "0 260 399 260", "0 284 399 284",
        "0 308 399 308", "0 332 399 332", "0 356 399 356", "0 380 399 380",
        "0 404 399 404", "0 428 399 428", "0 452 399 452", "0 476 399 476",
        "0 500 399 500", "0 524 399 524", "0 548 399 548", "0 572 399 572",
        "0 596 399 596", "5 0 5 599", "21 0 21 599", "37 0 37 599",
        "53 0 53 599", "69 0 69 599", "85 0 85 599", "101 0 101 599",
        "117 0 117 599", "133 0 133 599", "149 0 149 599", "165 0 165 599",
        "181 0 181 599", "197 0 197 599", "213 0 213 599", "229 0 229 599",
        "245 0 245 599", "261 0 261 599", "277 0 277 599", "293 0 293 599",
        "309 0 309 599", "325 0 325 599", "341 0 341 599", "357 0 357 599",
        "373 0 373 599", "389 0 389 599"});

  return 0;
}
