#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PII pair<int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define D(x) cerr << #x " is " << (x) << endl

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