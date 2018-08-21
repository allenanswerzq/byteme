#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  string shiftingLetters(string S, vector<int>& shifts) {
    int n = sz(shifts);
    ford(i, n-2, -1) {
      shifts[i] = (shifts[i] % 26 + shifts[i+1] % 26) % 26;
    }

    fori(i, 0, n) {
      S[i] = 'a' + (S[i] - 'a' + shifts[i]) % 26;
    }     
    return S;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
