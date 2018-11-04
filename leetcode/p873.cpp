#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lenLongestFibSubseq(vector<int>& aa) {
    int n = sz(aa);
    uset<int> st;
    fora (a, aa) st.insert(a);
    int res = 0;
    fori (i, 0, n) {
      fori (j, i + 1, n) {
        int tmp = 2;
        int one = aa[i], two = aa[j];
        while (st.count(one + two)) {
          ++tmp;
          int three = one + two;
          one = two; two = three;
        }
        if (tmp > 2) res = max(res, tmp);
      }
    }
    return res;
  }
};

int main() {
  return 0;
}
