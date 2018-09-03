#include<bits/stdc++.h>

using namespace std;

vector<int> majorityElement(vector<int>& nums) {
  int n = nums.size();
  if (n <= 0) return {};
  int c1=0, c2=0, candidate1=(1<<28), candidate2=(1<<28);
  for (auto x: nums) {
  if (x == candidate1)
  c1++;
  else if (x == candidate2)
  c2++;
  else if (c1 == 0) {
  candidate1 = x;
  c1 = 1;
  } else if (c2 == 0) {
  candidate2 = x;
  c2 = 1;
  } else {
  c1--;
  c2--;
  }
  }

  int n1=0, n2=0;
  for (auto x: nums) {
  if (x == candidate1) n1++;
  if (x == candidate2) n2++;
  }

  vector<int> res;
  if (n1 > n/3) res.push_back(candidate1);
  if (n2 > n/3) res.push_back(candidate2);
  return res;
}

