#include<bits/stdc++.h>
using namespace std;

class LargestCircle {
public:
  vs grid;
  int height, width;
  int dist(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  }

  bool check(int x, int y, int r) {
    int rs = r * r;
    fori (i, 0, height) {
      fori (j, 0, width) {
        int d1 = dist(i, j, x, y);
        int d2 = dist(i + 1, j, x, y);
        int d3 = dist(i, j + 1, x, y);
        int d4 = dist(i + 1, j + 1, x, y);
        if (d1 >= rs && d2 >= rs && d3 >= rs && d4 >= rs) continue;
        if (d1 <= rs && d2 <= rs && d3 <= rs && d4 <= rs) continue;
        if (grid[i][j] == '#') return false;
      }
    }
    return true;
  }

  int radius(vs aa) {
    grid = aa;
    height = sz(grid);
    width = sz(grid[0]);
    int res = 0;
    fori (i, 1, height) fori (j, 1, width) {
      int r_max = min(min(i, height-i), min(j, width-j));
      fori (r, 1, r_max+1)
        // Use <i,j> as circle center point and r as radius.
        if (check(i, j, r))
          res = max(res, r);
    }
    return res;
  }
};

void test(vs aa) {
  LargestCircle go;
  int r = go.radius(aa);
  output(r);
}

int main() {
    test({"############",
          "###......###",
          "##.######.##",
          "#.########.#",
          "#.##..####.#",
          "#.##..####.#",
          "#.########.#",
          "#.########.#",
          "#.########.#",
          "##.######.##",
          "###......###",
          "############"});
  return 0;
}
