#include <bits/stdc++.h>
class BridgeCrossing {
public:
  int visit[6];
  int visit_cnt;
  vi times;
  int tot, min_time;
  int n;

  void sendTwo() {
    fori (i, 0, n) {
      fori (j, i + 1, n) {
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
            fori (i, 0, n) {
              if (visit[i] && times[i]<fast) {
                fast_id = i;
                fast = times[i];
              }
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
    mst(visit, 0);
    n = sz(times);
    min_time = 0x30303030;
    tot = 0;
    sendTwo();
    return min_time;
  }
};

void test(vi aa) {
  BridgeCrossing go;
  int r = go.minTime(aa);
  output(r);
}

int main() {
  test({1, 2, 5, 10});
  test({1, 2, 3, 50, 99, 100});
  test({100});
  return 0;
}
