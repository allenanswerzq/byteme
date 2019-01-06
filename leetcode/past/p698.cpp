#include <bits/stdc++.h>
using namespace std;

// ref: http://www.geeksforgeeks.org/partition-set-k-subsets-equal-sum/
// ref: https://www.hackerearth.com/practice/notes/bit-manipulation/

bool dfs(vi& aa, vvi& path, vi& subSetSum, vi& taken, int sum, int idx, int k, int lastIdx) {
  if (subSetSum[idx] == sum) {
    if (idx == k-1) return true;
    return dfs(aa, path, subSetSum, taken, sum, idx+1, k, aa.size()-1);
  }

  // lastIdx from where elements should be taken
  // Use this to avoid repeat already tested elements
  for (int i = lastIdx; i >= 0; --i) {
    if (taken[i]) continue;
    int tmp = subSetSum[idx] + aa[i];
    if (tmp <= sum) {
      taken[i] = 1;
      subSetSum[idx] += aa[i];
      path[idx].push_back(aa[i]);
      bool next = dfs(aa, path, subSetSum, taken, sum, idx, k, i-1);

      // After taken aa[i] we can partition then just return
      if (next) return true;

      // If cannt, remove already taken aa[i] and find a new one
      taken[i] = 0;
      subSetSum[idx] -= aa[i];
      path[idx].pop_back();

    }
  }

  return false;
}

// Every element exactly in one partition namely cannt use elements mulit times
bool canPartitionKSubsets(vi& aa, int k) {
  int N = aa.size();
  if (k == 1) return true;
  if (k > N) return false;

  int sum = 0;
  for (auto n: aa) sum += n;

  // If sum cant divide by k then we cant partition k subsets that have euqal sum
  if (sum % k != 0) return false;

  sum /= k;
  vi subSetSum(k, 0);
  vi taken(N, 0);
  vvi path(k); // save the partition result

  subSetSum[0] = aa[N-1];
  taken[N-1] = 1;
  path[0].push_back(1);

  bool ret = dfs(aa, path, subSetSum, taken, sum, 0, k, N-1);
  return ret;
}

// bit manipulation approach
/* Assume there are four elements in array
   for every subsets use 1 and 0 to decide which elements included in subsets
   i.e. [5 4 7 8] k=2
   from 1111 to 0000 there are 2^4 = 16 different choices
   subset 1: [5, 7]  bits representation: 1010
   subset 2: [4, 8]  bits representation: 0101
   decrese from 15 to 0 we can get all bits representations
*/

vector<int> a;
int dfs(int bit, int sum) {
  if (bit == 0) return 1;
  for (int i= (1 << a.size())-1; i >= 0; i--) {
    i &= bit;

    int tot = 0;
    for (int j = 0; j < a.size(); j++)
      if (i & (1 << j)) tot += a[j];

    if (tot == sum) {
      int tmp = dfs(bit ^ i, sum);
      if (tmp) return 1;
    }
  }
  return 0;
}

class Solution {
public:
  bool canPartitionKSubsets(vector<int>& aa, int k) {
    int i, sum = 0;
    for (i = 0; i < aa.size(); i++) sum += aa[i];
    if (sum % k != 0) return false;
    sum /= k; a = aa;
    return dfs((1 << a.size()) - 1, sum);
  }
};
