#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool checkSubarraySum(vector<int>& aa, int k) {
  int n = sz(aa);
  if (n < 2) return 0; 
  if (k == 0) k = inf;
  unordered_set<int> st;
  int old = 0;
  // (a + nk) % k = a % k
  fora (a, aa) {
    int sum = old + a; 
    if (st.count(sum % k)) return 1;
    st.insert(sum % k);
    old = sum;
  }
  return 0;
  }
};

// class Solution {
// public:
//   // Naive approach.
//   bool checkSubarraySum(vector<int>& aa, int k) {
//     int n;
//     n = sz(aa);
//     fori (i, 0, n) {
//       int sum = 0;
//       ford (j, i, -1) {
//         sum += aa[j];
//         if (j < i) {
//           if (k && sum % k == 0)
//             return 1;
//           else if (k == 0) {
//             if (sum == 0) 
//               return 1;    
//           }
//         }
//       }
//     } 
//     return 0;
//   }
// };

void test(vi aa, int k) {
  Solution go;
  int r = go.checkSubarraySum(aa, k);
  cerr(r);    
}

int main() {
   // test({0, 0}, 0);
  test({23, 2, 4, 6, 7}, 6);
  // test({23, 2, 4, 6, 7}, 0);
  return 0;
}
