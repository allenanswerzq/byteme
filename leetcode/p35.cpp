#include<bits/stdc++.h>using namespace std;

#define all(x) (x).begin(), (x).end()

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    return (lower_bound(all(nums), target) - nums.begin());
  }
};

void test(vector<int> aa, int bb) {
  Solution go;
  int r = go.searchInsert(aa, bb);
  cout << r << endl;
}

int main() {
  test({1, 3, 5, 6}, 7);
  return 0;
}
