#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
  map<int, int> mp;
  for (auto x: nums)
    if (mp.count(x)) mp[x] = 1;
    else return true;
  return false;
}

int main(int argc, char** argv) {
  return 0;
}
