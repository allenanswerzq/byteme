#include<bits/stdc++.h>
using namespace std;

bool cmp(pii a, pii b) {
  return a.fi * b.se < a.se * b.fi;
}

class Solution {
public:
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
  int n = sz(quality);
  vector<pii> pp;
  fori(i, 0, n) {
    pp.eb(wage[i], quality[i]);
  } 

  sort(all(pp), cmp); 

  double ans = 1e27;
  ll sum = 0;
  // multiset can be used as a heap here.
  multiset<int> q;

  fori(i, 0, n) {
    q.insert(pp[i].se);
    sum += pp[i].se; 
    // Note: can not call earse directly on reverse_iterator.
    if (sz(q) > K) {
    sum -= *q.rbegin();
    q.erase(prev(q.end()));
    }

    if (sz(q) == K)
    ans = min(ans, sum * pp[i].fi * 1.0 / pp[i].se);
  }
  return ans;
  }
};

int main() {
   return 0;
}
