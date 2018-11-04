#include<bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define output(val) cout << (val) << endl;
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
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

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

class RLEIterator {
public:
  vpii mp;
  RLEIterator(vector<int> aa) {
    for (int i = 1; i < sz(aa); i += 2) {
      if (aa[i - 1])
        mp.push_back({aa[i], aa[i - 1]}); 
    }
    // fora (a, mp) trace(a.first, a.second);
  }
  
  int next(int kk) {
    for (int i = 0;  i < sz(mp); ++i) {
      // trace(i, mp[i].second, kk);
      if (mp[i].second >= kk) {
        mp[i].second -= kk;
        return mp[i].first;
      } else {
        kk -= mp[i].second;
        mp[i].second = 0; 
      }
    }
    return -1;
  }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */

void test(vi aa) {
  RLEIterator go(aa);
  output(go.next(2)); 
  output(go.next(1));
  output(go.next(1));
  output(go.next(2)); 
}

void test2(vi aa) {
  RLEIterator go(aa);
  output(go.next(358));
  output(go.next(345));
  output(go.next(154));
  output(go.next(265));
  output(go.next(73));
  output(go.next(220));
  output(go.next(138));
  output(go.next(4));
  output(go.next(170));
  output(go.next(88));
}

int main() {
  // test({3, 8, 0, 9, 2, 5});
  test2({811,903,310,730,899,684,472,100,434,611});
  return 0;
}
