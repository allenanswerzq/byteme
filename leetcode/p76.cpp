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

// TODO
class Solution {
public:
  string minWindow(string ss, string tt) {
    vector<int> map(128, 0);
    for (auto c : tt) map[c]++;
    int counter = tt.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
    while (end < ss.size()) {
      if (map[ss[end++]]-- > 0) counter--;
      while (counter == 0) {
        if (end - begin < d) {
          d = end - begin;
          head = begin;
        }
        if (map[ss[begin++]]++ == 0) counter++;
      }  
    }
    return d == INT_MAX? "" : ss.substr(head, d);
  }
};

void test(string aa, string bb) {
  Solution go;
  string r = go.minWindow(aa, bb);
  output(1, r);
}

int main(int argc, char** argv) {
  test("ADOBECODEBANC", "ABC");
  return 0;
}
