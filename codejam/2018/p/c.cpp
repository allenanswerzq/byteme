#include<bits/stdc++.h>
using namespace std;

unordered_map<string, pair<string, string>> mp;

string recu(string start) {
  string dst = mp[start].se;
  if (dst == "") return "";
  string res = start;
  if (dst != "") {
    res += "-" + dst + " " + recu(mp[start].se); 
  }
  return res;
}

string go() {
  string start, end;
  fora (a, mp) {
    string cur = a.fi;
    auto info = a.se;
    // trace(cur, info.fi, info.se);
    if (info.fi == "")
      start = cur;
    if (info.se == "")
      end = cur; 
  }
  // trace(start, end);
  return recu(start);  
}

int main() {
 
  int t; cin >> t;
  fori (i, 0, t) {
    mp.clear(); 
    int n; cin >> n;
    while (n--) {
      string a, b;
      cin >> a; cin >> b;
      // trace(a, b);
      // Parent
      mp[b].fi = a;
      // Child
      mp[a].se = b;
    } 
    string res = go();
    cout << "Case #" << i + 1 << ": " << res << endl;
  }

  return 0;
}
