#include <bits/stdc++.h>
using namespace std;

string inp;
bool replace(int idx, string src, string dst) {
  int n = sz(src);
  if (inp.substr(idx, n) == src) {
    string aa = inp.substr(0, idx);
    string bb = inp.substr(idx + n);
    inp = aa + dst + bb;
    return true;
  }
  return false;
}

class Solution {
public:
  string findReplaceString(string S, vi& indexes, vs& sources, vs& targets) {
    inp = S;
    int n = sz(indexes);
    map<int, pair<string, string>> mp;

    fori(i, 0, n) {
      mp[indexes[i]] = mk(sources[i], targets[i]);
    }

    int off = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
      int idx = it->fi + off;
      string src = it->se.fi;
      string dst = it->se.se;
      // cout << idx << " " << src << " " << dst << endl;
      if (replace(idx, src, dst)) {
        off += sz(dst) - sz(src);
      }
    }
    return inp;
  }
};

int main() {
  return 0;
}
