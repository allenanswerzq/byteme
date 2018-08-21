#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
int cmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class FairWorkload
{
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
      fori(i, 0, n) {
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

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  vi aa = {10, 20, 30, 40, 50, 60, 70, 80, 90};
  FairWorkload go;
  cout << go.getMostWork(aa, 3) << "\n";
  return 0;
}
