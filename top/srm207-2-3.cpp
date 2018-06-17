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

class CaptureThemAll { 
public: 
  int dist[9][9]; 
  int doit(string from, string to) 
  { 
    vector<vi> dir = {{-2,-1}, {-2,1}, {2,-1}, {2,1}, {-1,-2}, {1,-2},
                    {-1,2}, {1,2}};
    queue<string> Q;
    Q.push(from);
    // Note: use memset could cause problems sometime.
    fori(i, 0, 10)
      fori(j, 0, 10)
        dist[i][j] = 1000;
    // mst(dist, 1000);
    // fori(i, 0, 10)
    //   fori(j, 0, 10)
    //     cout << dist[i][j] << ' ';

    // Note: index 
    dist[from[0] - 'a' + 1][from[1]-'0'] = 0;
    int tc = to[0] - 'a' + 1;
    int tr = to[1] - '0';

    while (!Q.empty()) {
      string top = Q.front(); Q.pop();
      if (top == to)
        return dist[tc][tr];
        int c = top[0]-'a'+1;
        int r = top[1]-'0';
        fora(d, dir) {
          int nc = c + d[0]; int nr = r + d[1];
          if(0<nc && nc<9 && 0<nr && nr<9) {
            if (dist[c][r] + 1 < dist[nc][nr]) {
              dist[nc][nr] = dist[c][r] + 1;
              string nxt_state;
              nxt_state += (char)('a' + nc - 1);
              nxt_state += (char)('0' + nr);
              Q.push(nxt_state);
            }
          }
        }
    }
    return -1;
  }

  int fastKnight (string knight, string rook, string queen) {
    int a = doit(knight, rook) + doit(rook, queen);
    int b = doit(knight, queen) + doit(queen, rook);
    // int c = 2*doit(knight, rook) + doit(knight, queen);
    // int d = 2*doit(knight, queen) + doit(knight, rook);
    // cout << a << " " << b << " " << c << " " << d << '\n';
    // return min(min(a, min(b, c)), d);
    return min(a, b);
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  CaptureThemAll go;
  cout << go.fastKnight("a1", "b3", "c5") << '\n';
  cout << go.fastKnight("b1", "c3", "a3") << '\n';
  cout << go.fastKnight("a1", "a2", "b2") << '\n';
  cout << go.fastKnight("a5", "b7", "e4") << '\n';
  cout << go.fastKnight("h8", "e2", "d2") << '\n';
  return 0;
}