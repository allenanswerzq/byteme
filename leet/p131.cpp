#include<bits/stdc++.h>
using namespace std;

#define vs vector<string>
#define vvs vector<vector<string>>

class Solution {
public:
  bool isPalindrome(string ss) {
    if (ss == "") return true;
    int lo = 0, hi = ss.size() - 1;
    while (lo < hi) {
      if (ss[lo] == ss[hi]) {
        ++lo; --hi;
      } else {
        return false;
      }
    }
    return true;
  }

  void bt(string ss, vvs& res, vs& path) {
    if (ss == "") {
      res.push_back(path);
      return;
    }
    
    for (int i = 1; i <= ss.size(); ++i) {
      string front = ss.substr(0, i);
      if (isPalindrome(front)) {
        path.push_back(front);
        bt(ss.substr(i), res, path);
        path.pop_back();
      }
    }
  }

  vvs partition2(string ss) {
    vvs res;            
    vs path;
    if (ss == "") return res;
    bt(ss, res, path);
    return res;
  }

  vvs partition(string ss) {
    vvs rest;            
    vvs res;            
    if (ss == "") return res;

    for (int i = 1; i <= ss.size(); ++i) {
      string front = ss.substr(0, i);
      if (isPalindrome(front)) {
        rest = partition(ss.substr(i));
        if (rest.size() == 0) {
          res.push_back({front});
        } else {
          for (auto& r : rest) {
            r.insert(r.begin(), front);
            res.push_back(r);
          }
        }
      }
    }

    return res;
  }
};

int main(int argc, char** argv) {
  return 0;
}
