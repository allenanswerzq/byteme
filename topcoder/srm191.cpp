#include<bits/stdc++.h>
using namespace std;

class BettingMoney {
public:
  int moneyMade(vi& amounts, vi& bb, int ix) {
    long r = 0;
    fora(x, amounts)
      r += x;
    return (r-amounts[ix])*100 - amounts[ix]*bb[ix];
  }
};

vi parse(string s) {
  vi aa;
  int i=1, j=2;
  while (j < sz(s)) {
    while ('0'<=s[j] && s[j]<='9')
      j++;
    int x = stoi(s.substr(i, j-1));
    aa.pb(x);
    i = j+1;
    j = j+2;
  }
  return aa;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  BettingMoney c;
  vi aa, bb;
  int ix;
  string s;
  int i = 0;

  while (cin >> s) {
    ++i;
    if(sz(s) > 1) {
      if (i == 1)
        aa = parse(s);
      if (i == 2)
        bb = parse(s);
    } 
    else ix = stoi(s);

    if (i == 3) { 
      i = 0;
      cout << c.moneyMade(aa, bb, ix) << '\n';
    }
  }
  return 0;
}
