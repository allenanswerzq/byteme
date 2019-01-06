#include <bits/stdc++.h>
using namespace std;

int distributeCandies(vector<int>& candies) {
  map<int, int> m;
  int n = candies.size() / 2;
  int ret;
  for (auto c : candies) m[c]++;
  return min(m.size(), n);
}

int main() {
  return 0;
}
