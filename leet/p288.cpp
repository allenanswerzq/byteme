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

// An abbreviation of a word follows the form <first letter><number><last letter>. 
// Below are some examples of word abbreviations:
// a) it                      --> it    (no abbreviation)
//      1
// b) d|o|g                   --> d1g
//               1    1  1
//      1---5----0----5--8
// c) i|nternationalizatio|n  --> i18n
//               1
//      1---5----0
// d) l|ocalizatio|n          --> l10n
// Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. 
// A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.
// Example: 
// Given dictionary = [ "deer", "door", "cake", "card" ]
// isUnique("dear") -> false
// isUnique("cart") -> true
// isUnique("cane") -> false
// isUnique("make") -> true

// #define LOCAL_FILE

class ValidWordAbbr {
public:
  ValidWordAbbr(vector<string>& dicts) {
  fora (a, dicts) {
    string t = a[0] + to_string(sz(a) - 2) + a.back();
    mp[t].insert(a);
  } 
  }

  bool isUnique(string aa) {
  string t = aa[0] + to_string(sz(aa) - 2) + aa.back();
  if (mp[t].count(aa) && sz(mp[t]) == 1) 
    return 1;
  return 0;
  }

private:
  unordered_map<string, set<string>> mp; 
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

#ifdef LOCAL_FILE
  freopen("p288-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();
#endif 

  int t; cin >> t;
  fori (i, 1, t + 1) {
  
  }  

#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
#endif

  return 0;
}
