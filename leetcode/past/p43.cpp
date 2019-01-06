#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Not that good, but accepted
  // reference: https://en.wikipedia.org/wiki/Multiplication_algorithm
  string multiply(string aa, string bb) {
    int p = aa.size();
    int q = bb.size();
    int product[p + q] = {0};     
    string ret = "";
    reverse(aa.begin(), aa.end());
    reverse(bb.begin(), bb.end());
    for (int i = 0; i < q; ++i) {
      int carry = 0;
      for (int j = 0; j < p; ++j) {
        product[i + j] += carry + (aa[j]-'0') * (bb[i]-'0');
        carry = product[i + j] / 10;
        product[i + j] = product[i + j] % 10;
      }
      product[i + p] += carry;
    }

    int i = p + q - 1;
    while (i >= 0 && !product[i]) --i;
    if (i == 0) return "0";
    while (i >= 0) {
      ret += product[i]+'0';
      --i;
    }
    return ret;
  }
};

void test(string aa, string bb) {
  Solution go;
  string ret = go.multiply(aa, bb);
  trace(ret);
}

int main() {
  test("1234", "1111");
  return 0;
}
