#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
  vvi generate(int inp) {
    vvi res;
    if (inp >= 1) {
      res.push_back({1});
    }

    if (inp >= 2) {
      res.push_back({1, 1});
    } 

    for (int i = 2; i < inp; ++i) {
      vi path;
      vi tmp = res[i - 1];
      for (int k = 0; k < tmp.size() - 1; ++k) {
        path.push_back(tmp[k] + tmp[k + 1]);
      }
      path.push_back(1);
      path.insert(path.begin(), 1);
      res.push_back(path);
    }
    return res;
  }
};

int main() {
  return 0;
}
