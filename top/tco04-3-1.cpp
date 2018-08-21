#include<bits/stdc++.h>
using namespace std;

        cout << "\n"; } cout << "\n"
        fori(i, 0, n) \
          fori(j, 0, m) \
            fori(k, 0, c) \
              x[i][j][k] = v
const double eps = 1e-9;
int cmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Boxing
{
public:
  int maxCredit(vi a, vi b, vi c, vi d, vi e) {
    int credits = 0;
    vi judges[5];
    judges[0] = a;
    judges[1] = b;
    judges[2] = c;
    judges[3] = d;
    judges[4] = e;

    fori(i, 0, 5) 
      cout << sz(judges[i]) << " ";
    cout << "\n";

    vi idx(5, 0);
    int lo = 0; // interval start.
    fori(i, 0, 180001) {
      if (i - lo > 1000) lo = i - 1000;
      int aa = 0;
      fori(j, 0, 5) {
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
      fori(k, 0, 5) {
        while (sz(judges[k])>idx[k] && judges[k][idx[k]] < lo)
          ++idx[k];
      }
    }  
    return credits;
  }  
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  Boxing go;
  vi a = {1,2,3,4,5,6};
  vi b = {1,2,3,4,5,6,7};
  vi c = {1,2,3,4,5,6};
  vi d = {0,1,2};
  vi e = {1,2,3,4,5,6,7,8};
  int r = go.maxCredit(a, b, c, d, e);
  cout << r << "\n";
  a = {100,200,300,1200,6000};
  b = {};
  c = {900,902,1200,4000,5000,6001};
  d = {0,2000,6002};
  e = {1,2,3,4,5,6,7,8};
  r = go.maxCredit(a, b, c, d, e);
  cout << r << "\n";
  return 0;
}
