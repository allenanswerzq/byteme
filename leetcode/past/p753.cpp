#include <bits/stdc++.h>
using namespace std;

typedef set<string> set_t;

bool dfs(set_t mp, string ret, int n, int k, int tot) {
  if (mp.size() == tot) return true;
  string pre = ret.substr(ret.size() - n + 1);
  for (int i=0; i<k; ++i) {
    string next = pre + to_string(i);
    if (mp.count(next)) continue;
    mp.insert(next);
    ret += to_string(i);
    if (dfs(mp, ret, n, k, tot)) return true;
    else {
      mp.erase(next);
      ret.pop_back();
    }
  }
  return false;
}

string crackSafe(int n, int k) {
  set_t mp;
  string ret(n, '0');
  int tot = pow(k, n);
  mp.insert(ret);
  dfs(mp, ret, n, k, tot);
  return ret;
}
