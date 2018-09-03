#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

vs dict;
unordered_map<string, vector<string>> mp;

bool check(string s) {
  fora (d, dict)
  if (d == s)
  return 1;
  return 0; 
}

void recu(string s, string path, vs& res) {
  int n = sz(s);
  if (n == 0) {
  path = path.substr(0, sz(path)-1);
  res.pb(path);
  return ;
  }
  
  fori (i, 1, n+1) {
  string pre = s.substr(n - i, i);
  // cout << "pre: " << pre << "\n";
  if (check(pre)) {
  recu(s.substr(0, n - i), pre + " " + path, res);
  }
  }
}

class Solution {
public:
  vector<string> wordBreak(string s, vector<string>& aa) {
  dict = aa;
  vs res;
  recu(s, "", res); 
  return res;
  }
};


void test(string s, vs aa) {
  Solution go;
  vs res = go.wordBreak(s, aa);    
  fora (s, res)
  cout << s << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  test("catsanddog", {"cat", "cats", "sand", "and", "dog"});
  test("pineapplepenapple", {"apple", "pen", "applepen", "pine", "pineapple"});
  // Hard case.
  // string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  // vstr aa = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
  // test(s, aa);
  return 0;
}
