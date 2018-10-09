#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pend cout << endl
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define outret(v) cout << (v) << endl
#define output(ix, v) cout << "Case #" << (ix) << ": " << (v) << endl
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if(v) pvar(x); fori(i, 0, n) cout << x[i] << " "; pend

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
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// ref: http://codeforces.com/blog/entry/62199 @rols @scutt_wu
// As JustAni pointed out: "The question can be converted into finding 
// a subarray each from A and B such that product of sum of elements of 
// those subarrays is less than or equal to x and the product of 
// their size is maximum."

// Now, for both arrays we can calculate in O(n^2) the minimum 
// sum achievable for interval sizes i=1..n, 
// i.e. for array "a" we can calculate "a_min" as 
// a_min[i] = min( sum(a[l]..a[r]) where r-l+1 = i), 
// and the same can be done for array "b".
// Now simply try all possibilities, track the current maximum and 
// try to update it to i*j when a_min[i] * b_min[j] <= x. 
// The time complexity of this step is sufficient, 
// as it takes O(n*m), and the previous step took O(n^2) + O(m^2).

// TODO
const int maxn = 2100;
int n, m;
ll aa[maxn], bb[maxn];
ll rows[maxn], cols[maxn];
ll x;

int main() {
  cin >> n >> m;
  fori (i, 0, n) cin >> aa[i];
  fori (i, 0, m) cin >> bb[i];

  cin >> x;
  fori (i, 0, maxn) {
    rows[i] = cols[i] = x + 1;
  }

  fori (i, 0, n) {
    ll sum = 0;
    fori (j, i, n) {
      sum += aa[j];
      rows[j - i + 1] = min(rows[j - i + 1], sum); 
    }  
  }

  fori (i, 0, m) {
    ll sum = 0;
    fori (j, i, m) {
      sum += bb[j];
      cols[j - i + 1] = min(cols[j - i + 1], sum); 
    }  
  }

  // par(aa, n, 1);
  // par(bb, n, 1);
  // par(rows, n + 1, 1);
  // par(cols, n + 1, 1);

  int ret = 0;
  fori (i, 1, n + 1) {
    fori (j, 1, m + 1) {
      if (rows[i] * cols[j] <= x) {
        ret = max (ret, i * j);
      }
    } 
  }
  outret(ret);
}

