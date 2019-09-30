#include<bits/stdc++.h>
using namespace std;

class Boxing {
public:
  int maxCredit(vi a, vi b, vi c, vi d, vi e) {
    int credits = 0;
    vi judges[5];
    judges[0] = a;
    judges[1] = b;
    judges[2] = c;
    judges[3] = d;
    judges[4] = e;

    fori (i, 0, 5)
      cout << sz(judges[i]) << " ";
    cout << "\n";

    vi idx(5, 0);
    int lo = 0; // interval start.
    fori (i, 0, 180001) {
      if (i - lo > 1000) lo = i - 1000;
      int aa = 0;
      fori (j, 0, 5) {
        if (sz(judges[j]) > idx[j]) {
          int time = judges[j][idx[j]];
          // If the jth judge pressed in this time interval.
          if (time>=lo && time<=i)
            ++aa;
        }
      }
      // If we can give credit.
      if (aa >= 3) {
        cout << "interval: " << lo << " " << i << "\n";
        lo = i + 1;
        ++credits;
      }
      // Remove all times inside this interval, and repeat.
      fori (k, 0, 5) {
        while (sz(judges[k])>idx[k] && judges[k][idx[k]] < lo)
          ++idx[k];
      }
    }
    return credits;
  }
};

void test(vi a, vi b, vi c, vi d, vi e) {
  Boxing go;
  auto r = go.maxCredit(a, b, c, d, e);
  output(r);
}

int main() {
  test({1,2,3,4,5,6}, {1,2,3,4,5,6,7}, {1,2,3,4,5,6},
       {0,1,2}, {1,2,3,4,5,6,7,8});
  test({100,200,300,1200,6000}, {}, {900,902,1200,4000,5000,6001},
      {0,2000,6002}, {1,2,3,4,5,6,7,8});
  return 0;
}
