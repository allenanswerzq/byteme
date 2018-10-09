#include<bits/stdc++.h>
using namespace std;

class FlowerGarden {
public:
  bool isBlock(int b1, int w1, int b2, int w2) {
    // As long as there is one time value locate inside another's time interval,
    // There will have blocking occur.
    return (b1 <= b2 && b2 <= w1) || (b1<=w2 && w2<=w1) ||
           (b2 <= b1 && b1 <= w2) || (b2<=w1 && w1<=w2);
  }

  vi getOrdering(vi height, vi bloom, vi wilt) {
    int n = sz(height);
    vi res(n);
    vi visit(n, 0);
    fori(i, 0, n) {
      // We must choose one type flower to plant at the first.
      // Need to find as taller as possible.
      int choose = -1;
      fori(j, 0, n) {
        // If this type of flower is already been planted.
        if (visit[j]) continue;
        bool block = false;
        // Otherwise check whether jth type of flower can be blocked by others
        // or not.
        fori(k, 0, n) {
          // If this type of flower is already be planted.
          // Or its the jth type of flower we want to check, continue
          if (k==j || visit[k]) continue;
          if (height[j]>height[k] && 
             isBlock(bloom[j], wilt[j], bloom[k], wilt[k])) {
            block = true; 
            break;
          }
        } 
        // For the jth type of flower, there exists blocking, meaning that its
        // height is taller than others and it can also block others, of course
        // we cant choose this type to plant in front, so continue.
        if (block) continue;
        else {
          // Note: we find one can be planted, but it might not be the tallest
          // we can plant on the front. So 2nd loop still need to loop.
          if (choose==-1 || height[j] > height[choose])
            choose = j;
        }
      }
      // Note: We really find one type that can be planted also is the most 
      // tallest we can choose.
      res[i] = height[choose];
      visit[choose] = 1;
    }
    return res;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  FlowerGarden go;
  vi aa = {5,4,3,2,1};
  vi bb = {1,1,1,1,1};
  vi cc = {365,365,365,365,365};
  vi dd = go.getOrdering(aa, bb, cc);
  pvi(dd);
  aa = {1,2,3,4,5,6};
  bb = {1,3,1,3,1,3};
  cc = {2,4,2,4,2,4};
  dd = go.getOrdering(aa, bb, cc);
  pvi(dd);
  return 0;
}
