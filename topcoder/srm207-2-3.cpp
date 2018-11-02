#include<bits/stdc++.h>
using namespace std;

class CaptureThemAll {
public:
  int dist[9][9];
  int go(string from, string to) {
    vector<vi> dirs = {{-2,-1}, {-2,1}, {2,-1}, {2,1},
                      {-1,-2}, {1,-2}, {-1,2}, {1,2}};
    queue<string> dq;
    dq.push(from);
    // Note: use memset could cause problems sometime.
    fori (i, 0, 10)
      fori (j, 0, 10)
        dist[i][j] = 1000;

    // Note: index
    dist[from[0] - 'a' + 1][from[1] - '0'] = 0;
    int tc = to[0] - 'a' + 1;
    int tr = to[1] - '0';

    while (!dq.empty()) {
      string top = dq.front(); dq.pop();
      if (top == to)
        return dist[tc][tr];
        int c = top[0] - 'a' + 1;
        int r = top[1] - '0';
        fora (d, dirs) {
          int nc = c + d[0]; int nr = r + d[1];
          if (0 < nc && nc < 9 && 0 < nr && nr < 9) {
            if (dist[c][r] + 1 < dist[nc][nr]) {
              dist[nc][nr] = dist[c][r] + 1;
              string nxt_state;
              nxt_state += (char)('a' + nc - 1);
              nxt_state += (char)('0' + nr);
              dq.push(nxt_state);
            }
          }
        }
    }
    return -1;
  }

  int fastKnight(string knight, string rook, string queen) {
    int a = go(knight, rook) + go(rook, queen);
    int b = go(knight, queen) + go(queen, rook);
    // int c = 2*go(knight, rook) + go(knight, queen);
    // int d = 2*go(knight, queen) + go(knight, rook);
    // cout << a << " " << b << " " << c << " " << d << '\n';
    // return min(min(a, min(b, c)), d);
    return min(a, b);
  }
};

void test(string aa, string bb, string cc) {
  CaptureThemAll go;
  int r = go.fastKnight(aa, bb, cc);
  output(r);
}

int main() {
  test("a1", "b3", "c5");
  test("b1", "c3", "a3");
  test("a1", "a2", "b2");
  test("a5", "b7", "e4");
  test("h8", "e2", "d2");
  return 0;
}
