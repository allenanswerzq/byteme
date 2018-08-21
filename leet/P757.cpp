#include<bits/stdc++.h>
using namespace std;


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
