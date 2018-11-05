#include <bits/stdc++.h>
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

struct Segtree {
  int n_;
  vector<int> data_;
#ifdef LAZY
  #define NOLAZY 2e9
  #define GET(node) (lazy[node] == NOLAZY ? data_[node] : lazy[node])
  vector<int> lazy;
#else
  #define GET(node) data_[node]
#endif
  void build_rec(int node, int* begin, int* end) {
    if (end == begin+1) {
      if (data_.size() <= node) data_.resize(node+1);
      data_[node] = *begin;
    } else {
      int* mid = begin + (end-begin+1)/2;
      build_rec(2*node+1, begin, mid);
      build_rec(2*node+2, mid, end);
      data_[node] = min(data_[2*node+1], data_[2*node+2]);
    }
  }
#ifndef LAZY
  void update_rec(int node, int begin, int end, int pos, int val) {
    if (end == begin+1) {
      data_[node] = val;
    } else {
      int mid = begin + (end-begin+1)/2;
      if (pos < mid) {
        update_rec(2*node+1, begin, mid, pos, val);
      } else {
        update_rec(2*node+2, mid, end, pos, val);
      }
      data_[node] = min(data_[2*node+1], data_[2*node+2]);
    }
  }
#else
  void update_range_rec(int node, int tbegin, int tend, 
                        int abegin, int aend, int val) {
    if (tbegin >= abegin && tend <= aend) {
      lazy[node] = val;
    } else {
      int mid = tbegin + (tend - tbegin + 1)/2;
      if (lazy[node] != NOLAZY) {
        lazy[2*node+1] = lazy[2*node+2] = lazy[node]; lazy[node] = NOLAZY;
      }
      if (mid > abegin && tbegin < aend)
        update_range_rec(2*node+1, tbegin, mid, abegin, aend, val);
      if (tend > abegin && mid < aend)
        update_range_rec(2*node+2, mid, tend, abegin, aend, val);
      data_[node] = min(GET(2*node+1), GET(2*node+2));
    }
  }
#endif
  int query_rec(int node, int tbegin, int tend, int abegin, int aend) {
    if (tbegin >= abegin && tend <= aend) {
      return GET(node);
    } else {
#ifdef LAZY
      if (lazy[node] != NOLAZY) {
        data_[node] = lazy[2*node+1] = lazy[2*node+2] = lazy[node]; 
        lazy[node] = NOLAZY;
      }
#endif
      int mid = tbegin + (tend - tbegin + 1)/2;
      int res = INT_MAX;
      if (mid > abegin && tbegin < aend) 
        res = min(res, query_rec(2*node+1, tbegin, mid, abegin, aend));
      if (tend > abegin && mid < aend)
        res = min(res, query_rec(2*node+2, mid, tend, abegin, aend));
      return res;
    }
  }

  // Create a segtree which stores the range [begin, end) in its bottommost level.
  Segtree(int* begin, int* end): n_(end - begin) {
    build_rec(0, begin, end);
#ifdef LAZY
    lazy.assign(data_.size(), NOLAZY);
#endif
  }

  Segtree(vector<int>& aa) : Segtree(&aa[0], &aa[0] + aa.size()) {}

#ifndef LAZY
  // Call this to update a value (indices are 0-based). 
  // If lazy propagation is enabled, use update_range(pos, pos+1, val) instaed.
  void update(int pos, int val) {
    update_rec(0, 0, n_, pos, val);
  }
#else 
  // Call this to update range [begin, end), if lazy propagation is enabled. 
  // Indices are 0-based.
  void update_range(int begin, int end, int val) {
    update_range_rec(0, 0, n_, begin, end, val);
  }
#endif
  // Returns minimum in range [begin, end). Indices are 0-based.
  int query(int begin, int end) {
    return query_rec(0, 0, n_, begin, end);
  }
};

const int mod = 1e9 + 7;
class Solution {
public:
  int sumSubarrayMins(vector<int>& aa) {
    int ret = 0;
    Segtree seg(aa);
    fori (i, 0, sz(aa))
      fori (j, i, sz(aa)) {
        int tmp = seg.query(i, j + 1);
        ret = (ret% mod + tmp % mod) % mod;
      }
    return ret;
  }
};

class Solution2 {
public:
  int sumSubarrayMins(vector<int>& aa) {
    int n = aa.size();
    vpii pp(n);
    fori (i, 0, n) pp[i] = make_pair(aa[i], i);
    sort(all(pp));
    ll ans = 0;
    set<int> st;
    st.insert(-1);
    st.insert(n);
    fori (i, 0, n) {
      int pos = pp[i].second;
      auto it = st.lower_bound(pos);
      int r = *it, l = *prev(it);
      // trace(l, r, pos);
      // trace(pos - l, r - pos);
      ans += ll(pos - l) * (r - pos) % mod * pp[i].first;
      ans %= mod;
      st.insert(pp[i].second);
    }
    return ans;
  }
};


void test(vi aa) {
  Solution2 go;
  int r = go.sumSubarrayMins(aa);
  output(r);
}

int main() {
  test({3, 1, 2, 4});
  return 0;
}
