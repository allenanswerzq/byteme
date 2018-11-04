#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    vector<string> stk;
    stringstream ss(path);
    string seg = "";

    while (getline(ss, seg, '/')) {
      if (seg == "..") {
        if (!stk.empty())
          stk.pop_back();
      } else if (seg != "" && seg != ".")
        stk.push_back(seg);
    }

    string res;
    for (auto& seg : stk) {
      res = res + '/' + seg;
    }

    return stk.empty() ? "/" : res;
  }
};

int main() {
  return 0;
}
