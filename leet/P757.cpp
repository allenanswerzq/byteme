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
#define D(x) cerr << #x " is " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

bool cmp(vector<int> a, vector<int> b) {
	return a[1] < b[1];
}

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
    	vector<vector<int>> a = intervals;
    	// sort use lamda function
			sort(a.begin(), a.end(), [](const vector<int>& a, const vector<int>& b) {
				return a[1] < b[1];	
			}); 

			set<int> ret;
			int n = a.size();
			For(i, 0, n) {
				int cnt = 0;
				for (auto it: ret) {
					if (it>=a[i][0] && it<=a[i][1]) cnt++;
					if (cnt >= 2) break;
				}
				int last = a[i][1];
				while (cnt < 2) {
					// Note: we must check this
					if (!ret.count(last))	{
						ret.insert(last);
						cnt++;
					}
					--last;
				}
			}
			return ret.size();
    }
};