#include<bits/stdc++.h>
using namespace std;

class FairWorkload {
public:
  // Predicate: Can x folders be assigned to each worker, with the limited
  // number of workers available?
  // If assign x can, then all number greater than x also can. and x might be
  // the minimum number of the maximum number of folders that can be assigned.
  int getMostWork(vi folders, int workers) {
    int n = sz(folders);
    int lo = *max_element(all(folders));
    int hi = accumulate(all(folders), 0);

    while (lo < hi) {
      int x = lo + (hi - lo)/2;

      int required = 1, curr_folders = 0;
      fori (i, 0, n) {
        if (curr_folders + folders[i] <= x)
          curr_folders += folders[i];
        else {
          ++required;
          curr_folders = folders[i];
        }
      }

      if (required <= workers)
        hi = x;
      else
        lo = x + 1;
    }
    return lo;
  }

};

void test(vi aa) {
  FairWorkload go;
  int r = go.getMostWork(aa);
  output(r);
}

int main() {
  test({10, 20, 30, 40, 50, 60, 70, 80, 90});
  return 0;
}
