#include<bits/stdc++.h>
using namespace std;

class BettingMoney {
public:
  int moneyMade(vi& amounts, vi& bb, int ix) {
    long r = 0;
    fora (x, amounts)
      r += x;
    return (r - amounts[ix]) * 100 - amounts[ix] * bb[ix];
  }
};

int main() {
  return 0;
}
