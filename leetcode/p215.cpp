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
  // Min heap
  int findKthLargest(vector<int>& aa, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    fori (i, 0, sz(aa)) {
      pq.push(aa[i]);
      if (sz(pq) >= k)
        pq.pop();
    }
    return pq.top();
  }

  int findKthLargest(vector<int>& aa, int k) {
    multiset<int> mset(all(aa));
    int i = 1;
    for (auto it = mset.rbegin(); it! = mset.rend(); ++it) {
      if (i++ == k)
        return *it;
    }
    return 0;
  }

  // Divide and conquer
  int partition(vector<int>& aa, int left, int right) {
    int pivot = aa[left];
    int lo = left + 1, hi = right;
    while (lo < hi) {
      trace(lo, hi);
      if (aa[lo] <= pivot && aa[hi] > pivot) {
        swap(aa[lo++], aa[hi--]);
      }
      if (aa[lo] >= pivot) ++lo;
      if (aa[hi] <= pivot) --hi;
    } 
    swap(aa[left], aa[hi]);
    return hi;
  }

  int findKthLargest(vector<int>& aa, int k) {
    int lo = 0, hi = sz(aa) - 1;
    while (1) {
      int pos = partition(aa, lo, hi);
      if (pos == k - 1) return aa[pos];
      else if (pos > k - 1) hi = pos - 1;
      else lo = pos + 1; 
    }
    return 0;
  }
};

void test(vi aa, int kk) {
  Solution go;
  int ret = go.findKthLargest(aa, kk);
  output(1, ret);
}

int main() {
  test({3,2,3,1,2,4,5,5,6}, 4);
  return 0;
}
