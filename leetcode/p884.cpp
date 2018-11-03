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

class Solution {
public:
  vs uncommonFromSentences(string aa, string bb) {
    unordered_map<string, int> sa;
    unordered_map<string, int> sb;
    istringstream isa(aa);
    istringstream isb(bb);
    vs ret;
    string tt;
    while (isa >> tt) sa[tt]++;
    while (isb >> tt) sb[tt]++;
    fora (a, sa) 
      if (!sb.count(a.first) && a.second == 1) 
        ret.push_back(a.first);

    fora(b, sb)
      if (!sa.count(b.first) && b.second == 1) 
        ret.push_back(b.first);

    return ret;
  }
};

void test(string aa, string bb) {
  Solution go;
  vs ret = go.uncommonFromSentences(aa, bb);
  pvi(ret);
}

int main(int argc, char** argv) {
  test("this apple is sweet", "this apple is sour");
  test("apple apple", "banana");
  return 0;
}
