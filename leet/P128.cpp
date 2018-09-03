#include<bits/stdc++.h>
using namespace std;

// Note: duplicate problem
int longestConsecutive(vector<int>& nums) { 
  unordered_set<int> st(nums.begin(), nums.end());         
  int best = 0;
  for (auto x:st) {
  if (st.find(x - 1) == st.end()) {
  int y = x + 1;
  while (st.find(y) != st.end()) ++y;
  best = max(best, y - x);
  }
  }
  return best;
}

int longestConsecutive(vector<int>& nums) { 
  unordered_map<int, int> m;
  int best = 0;
  for (auto x: nums) {
  if (m.find(x) == m.end()) {
  int l = m.find(x-1) == m.end() ? 0: m[x-1];
  int r = m.find(x+1) == m.end() ? 0: m[x+1];
  int sum = l + r + 1;
  best = max(best, sum);
  m[x] = sum;
  m[x - l] = sum;
  m[x + r] = sum;
  } 
  }
  return best;
}

int main(int argc, char** argv) {
  return 0;
}
