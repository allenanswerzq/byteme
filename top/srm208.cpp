#include<bits/stdc++.h>
using namespace std;



const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class TallPeople {
public:
  vi getPeople(vector<string>& mat) {
    vector<vi> matrix;
    for (auto row: mat) {
      istringstream iss(row);
      int x;
      vi tmp;
      while (iss >> x) {
        tmp.pb(x);
      }
      matrix.pb(tmp); 
    }
    int r = sz(matrix), c= sz(matrix[0]);
    int rm = INT_MAX, rh = 0;
    fora(row, matrix) {
      fora(x, row) {
        if (x < rm) rm = x;
        if (rm > rh) rh = rm;
      }
    }

    int cm = 0, ch = INT_MAX;
    fori(i, 0, c) {
      fori(j, 0, r) {
        int x = matrix[j][i];
        if (x > cm) cm = x;
        if (cm < ch) ch = cm;
      }
    }

    return {rh, ch};
  };
};

// int main(int argc, char** argv) {
//   std::ios_base::sync_with_stdio(false);
//   return 0;
// }
