#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
  string fractionToDecimal(ll n, ll d) {
    if (n == 0) return "0"; 
    string res; 
    if (n<0 ^ d<0) res += '-';
    n = llabs(n), d = llabs(d);  
    res += to_string(n / d);
    if (n % d == 0) return res;
    res += '.';
    unordered_map<int, int> mp;
    for (ll r = n % d; r; r %= d) {
      if (mp.count(r)) {
        res.insert(mp[r], 1, '(');
        res += ')'; 
        break;
      }
      mp[r] = res.size();
      r *= 10;
      // cout << r << " " << d << " " << r / d << endl;
      res += to_string(r / d);
    }
    return res;
  }

};

int main(int argc, char** argv) {
  Solution go;
  cout << go.fractionToDecimal(1, 7) << endl;
  cout << go.fractionToDecimal(-1, -2147483648) << endl;
  return 0;
}
