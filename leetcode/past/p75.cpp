#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void sortColors(vector<int>& aa) {
    vector<int> cnt(3, 0);
    for (auto& a : aa) {
      if(a == 0) cnt[0]++;
      else if(a == 1) cnt[1]++;
      else if(a == 2) cnt[2]++;
    }

    for (int i = 0, k = 0; i < 3; ++i)
      for (int j = 0; j < cnt[i]; ++j)
        aa[k++] = i;
    return;
  }

  void sortColors2(vector<int>& aa) {
    int zero = 0, two = aa.size() - 1;
    for (int k = 0; k <= two;) {
      if (aa[k] == 0) swap(aa[k++], aa[zero++]);
      else if(aa[k] == 2) swap(aa[k], aa[two--]);
      else k++;
    }
    return;
  }
};

int main() {
  return 0;
}
