#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxArea(vector<int>& aa) {
    int water = 0;
    int i = 0, j = aa.size() - 1;
    while (i < j) {
      int h = min(aa[i], aa[j]);
      water = max(water, (j - i) * h);
      while (aa[i] <= h && i < j) i++;
      while (aa[j] <= h && i < j) j--;
    }
    return water;
  }

  int maxArea(vector<int>& aa) {
    int res = 0, i = 0, j = aa.size() - 1;
    while (i < j) {
      res = max(res, min(aa[i], aa[j]) * (j - i));
      aa[i] < aa[j] ? ++i : --j;
    }
    return res;
  }

  // burte force 
  int maxArea1(vector<int>& aa) {
    int ret = 0;
    for (int i = 0; i < aa.size(); ++i)
      for (int j = i + 1; j < aa.size(); ++j) {
        ret = max(ret, (j - i) * (aa[i] <= aa[j] ? aa[i] : aa[j]));
      }
    return ret;
  }
}

void test(vi inp) {
  Solution go;
  int res = go.maxArea(inp);
  output(1, res);
}

int main() {
  test({2, 1, 2});
  return 0;
}
