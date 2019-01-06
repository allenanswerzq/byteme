#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> restoreIpAddresses(string ss) {
    vector<string> ret;
    for (int a = 1; a <= 3; a++)
      for (int b = 1; b <= 3; b++)
        for (int c = 1; c <= 3; c++)
          for (int d = 1; d <= 3; d++)
            if (a + b + c + d == ss.size()) {
              int A = stoi(ss.substr(0,a));
              int B = stoi(ss.substr(a,b));
              int C = stoi(ss.substr(a+b,c));
              int D = stoi(ss.substr(a+b+c,d));
              if (A <= 255 && B <= 255 && C <= 255 && D <= 255) {
                string res = to_string(A) + "." + to_string(B) + "." + 
                             to_string(C) + "." + to_string(D);  
                if (res.size() == ss.size() + 3) {
                  ret.push_back(res);
                }
              }  
            }
    return ret;
  }

  void dfs(vector<string>& res, string path, string ss, int k) {
    if (ss == "" || k == 4) {
      if (ss == "" && k == 4) 
        res.push_back(path.substr(1));
      return;
    } else {
      // Note: leading zero
      // For example .010. is not true instead of .0.10. is true
      for (int i = 1; i <= (ss[0] == '0' ? 1 : 3) && i <= ss.size(); ++i) {
        string x = ss.substr(0, i);
        if (stoi(x) <= 255) 
          dfs(res, path + "." + x, ss.substr(i), k + 1);
      }
    }
  }

  vector<string> restoreIpAddresses2(string ss) {
    vector<string> res;
    dfs(res, "", ss, 0);
    return res;
  }
};

int main() {
  return 0;
}
