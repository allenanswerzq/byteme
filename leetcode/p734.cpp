#include<bits/stdc++.h>
using namespace std;

bool areSentencesSimilar(vs& a, vs& b, vector<pair<string, string>> p) {
  if (a.size() != b.size()) return false;
  int n = a.size();
  set<pair<string, string>> s;
  for (auto x : p) {
    s.insert(x);
    swap(x.first, x.second);
    s.insert(x);
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i] && s.count({a[i], b[i]})==0)
      return false;
  }
  return true;
}
