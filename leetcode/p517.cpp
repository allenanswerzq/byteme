#include<bits/stdc++.h>
using namespace std;
// TODO
class Solution {
public:
  int findMinMoves(vector<int>& aa) {
  int sum, res, n, avg, cnt;
  n = sz(aa);
  sum = accumulate(all(aa), 0); 
  if (sum % n != 0) return -1;
  avg = sum / n;
  res = 0;
  fora (a, aa) {
    cnt += a - avg;
    res = max(res, max(abs(cnt), a - avg));
  }
  return res;
  }
};

void test(vi aa) {
  Solution go;
  int r = go.findMinMoves(aa);
  cerr(r);    
}

int main() {
   test({1, 0, 5});
  return 0;
}
