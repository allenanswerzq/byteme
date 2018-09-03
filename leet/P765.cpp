#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  int minSwapsCouples(vector<int>& row) {
 			int n = SZ(row);
 			vector<int> index(n, 0);	       
 			FOR(i, 0, n)
 				index[row[i]] = i;	

 			int ret = 0;
 			for (int i=0; i<n; i+=2) {
 				// If current person's couple already sits on her or him side
 				// Very clever idea to use xor 1 instead of using mod 2 to distinguish 
 				if (index[row[i]^1] == i+1)
 					continue;
 				else {
 					// Now, we need to swap current person's husband or wife to her or him side
 					int p = index[row[i]^1];
 					// First swap their index
 					index[row[i]^1] = i+1;
 					index[row[i+1]] = p;
 					// Also swap their value
 					swap(row[p], row[i+1]);
 					++ret;
 				}
 			} 
 			return ret;
  }
};
