#include <bits/stdc++.h>
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

#define vi vector<int>
#define vvi vector<vi>

class Soltion {
public: 
  int trap1(vector<int>& aa) {
    int ret = 0;
    int n = aa.size();
    for (int i = 1; i < n - 1; i++) {
      int left_max = 0, right_max = 0;

      // Search the left side for max bar size
      for (int j = i; j >= 0; j--) { 
        left_max = max(left_max, aa[j]);
      }

      // Search the right side for max bar size
      for (int j = i; j < n; j++) { 
        right_max = max(right_max, aa[j]);
      }
      ret += min(left_max, right_max) - aa[i];
    }
    return ret;
  }

  int trap2(vi& aa) {
    int n = sz(aa);
    int left[n], right[n]; 
    mst(left, 0); mst(right, 0);

    // Pre-compute the left side's maximum value.
    left[0] = aa[0];
    fori (i, 1, n)
      left[i] = max(left[i - 1], aa[i]);

    right[n - 1] = aa[n - 1];
    ford (i, n - 2, -1)
      right[i] = max(right[i + 1], aa[i]);

    int ret = 0;
    fori (i, 0, n)
      ret += min(left[i], right[i]) - aa[i];

    return ret;
  }

  // TODO
  // Decreasing stack.
  int trap3(vector<int>& aa) {
    int ret = 0, i = 0;
    int n = sz(aa);
    deque<int> dq;
    while (i < n) {
      if (!sz(dq) || aa[i] <= aa[dq.back()])
        dq.push_back(i++);
      else {
        int top = dq.back(); dq.pop_back();
        if (!sz(dq)) continue; 
        int dist = i - dq.back() - 1; 
        int height = min(aa[dq.back()], aa[i]) - aa[top];
        ret += dist * height;
      }
    }
    return ret;
  }
};

void test(vi aa) {
  Soltion go;
  int ret = go.trap3(aa);
  trace(ret);
}

int main() {
  test({0,1,0,2,1,0,1,3,2,1,2,1});
  test({4,2,3});
  return 0;
}
