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
#define For(i, a, b) for (int i=(a); i<(b); ++i)
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
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
 			vector<vector<int>> matrix(N, vector<int>(N, 1));       
 			for (auto m: mines)
 				matrix[m[0]][m[1]] = 0;

 			vector<vector<int>> left(N, vector<int>(N, 0));
 			auto right=left, up=left, down=left;
 			for (int i=0; i<N; ++i) 
 				for (int j=0; j<N; ++j) {
 					if (matrix[i][j] == 1) {
 						left[i][j] = j==0 ? 1: left[i][j-1]+1;	
 						up[i][j] 	 = i==0 ? 1: up[i-1][j]+1;
 					}
 				}	

 			int ret = 0;
 			for (int i=N-1; i>=0; i--)
 				for (int j=N-1; j>=0; j--) {
 					if (matrix[i][j] == 1) {
 						right[i][j] = j==N-1 ? 1: right[i][j+1]+1;	
 						down[i][j] = i==N-1 ?  1: down[i+1][j]+1;
 						ret = max(ret, min(min(left[i][j], right[i][j]), 
 														   min(up[i][j], down[i][j])
 														   ));
 					}
 				}
 			return ret;
    }
};