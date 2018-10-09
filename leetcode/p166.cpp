#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define pvi(x) fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args> 
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ','); 
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...); 
} 

class Solution {
public:
  string fractionToDecimal(ll n, ll d) {
    if (n == 0) return "0"; 
    string res; 
    if (n < 0 ^ d < 0) res += '-';

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
      trace(r, d, r / d);
      res += to_string(r / d);
    }
    return res;
  }
};

void test(int a, int b) {
  Solution go;
  string ret = go.fractionToDecimal(a, b);
  output(1, ret);
}

int main(int argc, char** argv) {
  Solution go;
  test(1, 3);
  test(1, 7);
  test(-1, -2147483648);
  return 0;
}
