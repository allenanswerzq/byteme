#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) {
  int k %= nums.size();
  reverse(nums, 0, nums.size());
  reverse(nums, 0, k);
  reverse(nums, k+1, nums.size());    
}

int main(int argc, char** argv) {
  return 0;
}
