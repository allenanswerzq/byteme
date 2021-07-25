/* created   : 2020-10-01 10:40:37
 * accepted  : 2020-10-01 16:54:58
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

vector<int> count_sort(vector<int>& A, int D, int radix = 10) {
  int n = A.size();
  vector<int> cnt(radix);
  int v = 1;
  for (int i = 0; i < D; i++) {
    v *= radix;
  }
  for (int i = 0; i < n; i++) {
    cnt[(A[i] / v) % 10]++;
  }
  for (int i = 1; i < radix; i++) {
    cnt[i] += cnt[i - 1];
  }
  vector<int> ans(n);
  // NOTE: go backward to keep the order sorted before
  for (int i = n - 1; i >= 0; i--) {
    int d = (A[i] / v) % 10;
    ans[--cnt[d]] = A[i];
  }
  return ans;
}

vector<int> radix_sort(vector<int>& A, int radix = 10) {
  int mx = *max_element(A.begin(), A.end());
  int digit = log2(mx) / log2(radix) + 1;
  for (int i = 0; i < digit; i++) {
    A = count_sort(A, i, radix);
  }
  return A;
}

vector<int> bucket_sort(vector<int>& A) {
  int mi = *min_element(A.begin(), A.end());
  int mx = *max_element(A.begin(), A.end());
  int n = A.size();
  int bucket_num = n;
  int bucket_range = (mx - mi + 1 + bucket_num - 1) / bucket_num;
  vector<vector<int>> buckets(bucket_num);
  for (int i = 0; i < n; i++) {
    int idx = (A[i] - mi) / bucket_range;
    assert(0 <= idx && idx < bucket_num);
    buckets[idx].push_back(A[i]);
  }
  for (int i = 0; i < bucket_num; i++) {
    sort(buckets[i].begin(), buckets[i].end());
  }
  vector<int> ans;
  for (auto& it : buckets) {
    for (int t : it) {
      ans.push_back(t);
    }
  }
  return ans;
}

class Solution {
public:
  int maximumGapRadixSort(vector<int>& A) {
    if (A.size() < 2) return 0;
    A = radix_sort(A);
    int ans = 0;
    for (int i = 1; i < A.size(); i++) {
      ans = max(ans, A[i] - A[i - 1]);
    }
    return ans;
  }

  int maximumGapBucketSort(vector<int>& A) {
    if (A.size() < 2) return 0;
    A = bucket_sort(A);
    int ans = 0;
    for (int i = 1; i < A.size(); i++) {
      ans = max(ans, A[i] - A[i - 1]);
    }
    return ans;
  }

  int maximumGap(vector<int>& A) {
    return maximumGapBucketSort(A);
    // return maximumGapRadixSort(A);
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

int test(vector<int> A) {
  Solution sol;
  return dbg(sol.maximumGap(A));
}

void solve() {
  EXPECT(test({15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740}), 2901);
  EXPECT(test({3, 6, 9, 1}), 3);
  EXPECT(test({10}), 0);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
