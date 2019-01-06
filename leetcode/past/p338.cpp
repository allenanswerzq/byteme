#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

  int count(int inp) {
    int cnt = 0;
    while (inp) {
      inp = inp & (inp - 1);
      ++cnt;
    }
    return cnt;
  }

  vector<int> countBits(int aa) {
    vi res;
    fori(i, 0, aa+1) {
      res.pb(count(i));
    }
    return res;
  }
};

void ret(int inp) {
  Solution go;
  pvi(go.countBits(inp));
}

int main() {
  ret(5);
  return 0;
}
