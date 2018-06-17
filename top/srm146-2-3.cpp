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
#include <unistd.h>
using namespace std;

#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define fora(e, c) for (auto &e : c)
#define all(x) (x).begin(), (x).end()
#define len(x) strlen(x)
#define vi vector<int>
#define vs vector<string>
#define sz(x) ((int)(x).size())
#define pii pair<int, int>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf pop_front
#define ppb pop_back
#define pvi(x) fora(r, x) cout << r << ' '; cout << '\n'
#define cerr(x) cerr << #x " is " << (x) << endl
#define mst(x, n, v) fori(i, 0, n) x[i] = v
#define mst2(x, n, m, v) fori(i, 0, n) fori(j, 0, m) x[i][j] = v
#define mst3(x, n, m, c, v) \
        fori(i, 0, n) \
          fori(j, 0, m) \
            fori(k, 0, c) \
              x[i][j][k] = v
const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// class BridgeCrossing {
// public:
//   int visit[6];
//   int visit_cnt;
//   vi times;
//   int n;

//   int bt() {
//     if (n == 1) return times[0];
//     int res = 0x30303030;
//     fori(i, 0, n) {
//       fori(j, i+1, n) {
//         if (!visit[i] && !visit[j]) {
//           // Choose any two people and bring them to other side.
//           int tot = 0;
//           int dt = max(times[i], times[j]);
//           tot += dt;
//           visit[i] = visit[j] = 1;
//           visit_cnt += 2;

//           if (visit_cnt == n) {
//             // If all people are moved.
//             res = min(tot, res);
//           } else {
//             // Find the fastest one and send him/her back to the start side.
//             int fast = 0x30303030;
//             int fast_id = -1;
//             fori(i, 0, n)
//               if (visit[i] && times[i]<fast) {
//                 fast_id = i;
//                 fast = times[i]; 
//               }
//             tot += times[fast_id];
//             visit[fast_id] = 0;
//             --visit_cnt;
//             // 
//             tot += bt();
//             res = min(tot, res);

//             tot -= times[fast_id];
//             visit[fast_id] = 1;
//             ++visit_cnt;
//           }

//           tot -= dt;
//           visit[i] = visit[j] = 0;
//           visit_cnt -= 2;
//         }
//       }
//     }
//     return res;
//   }

//   int minTime(vi aa) {
//     times = aa;
//     mst(visit, 6, 0);
//     n = sz(times);
//     return bt();
//   }
// };

class BridgeCrossing {
public:
  int visit[6];
  int visit_cnt;
  vi times;
  int tot, min_time; 
  int n;

  void sendTwo() {
    fori(i, 0, n) {
      fori(j, i+1, n) {
        if (!visit[i] && !visit[j]) {
          int dt = max(times[i], times[j]);
          // if (tot + dt >= min_time)
          //   continue;
          tot += dt;
          visit[i] = visit[j] = 1;
          visit_cnt += 2;

          if (visit_cnt == n) {
            min_time = min(min_time, tot);
          } else {
            // Find the fastest one and send him/her back to the start side.
            int fast = 0x30303030;
            int fast_id = -1;
            fori(i, 0, n)
              if (visit[i] && times[i]<fast) {
                fast_id = i;
                fast = times[i]; 
              }
            tot += times[fast_id];
            visit[fast_id] = 0;
            --visit_cnt;
            sendTwo();
            tot -= times[fast_id];
            visit[fast_id] = 1;
            ++visit_cnt;
          }

          tot -= dt;
          visit[i] = visit[j] = 0;
          visit_cnt -= 2;
        }
      }
    }
  }

  int minTime(vi aa) {
    times = aa;
    mst(visit, 6, 0);
    n = sz(times);
    min_time = 0x30303030;
    tot = 0;
    sendTwo();
    return min_time;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  BridgeCrossing go;
  vi t = { 1, 2, 5, 10 }; 
  cout << go.minTime(t) << '\n';
  t = { 1, 2, 3, 50, 99, 100 };
  cout << go.minTime(t) << '\n';
  t = {100};
  cout << go.minTime(t) << '\n';
  return 0;
}
