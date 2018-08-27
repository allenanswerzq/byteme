#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	if (sz(nums) < 3) return res;
	sort(all(nums));
	// a + b + c = 0
	// b + c = -a;
	for (int i=0; i < nums.size()-2; ++i) {
		if (i==0 || (i>0 && nums[i-1] != nums[i])) {
			int lo = i + 1, hi = sz(nums) - 1;	
			int goal = -nums[i];
			while (lo < hi) {
				if (nums[lo] + nums[hi] == goal) {
					res.push_back({nums[i], nums[lo], nums[hi]});
					while (lo < hi && nums[lo] == nums[lo+1]) ++lo;
					while (lo < hi && nums[hi] == nums[hi-1]) --hi;
					++lo;
					--hi;
				}	
				else if (nums[lo] + nums[hi] < goal) ++lo;
				else --hi;
			}
		}
	}
	return res;
}

// burte force
vector<vector<int>> threeSum1(vector<int>& nums) {
	vector<vector<int>> ret;
	int n = nums.size();
	for (int i=0; i<n; ++i) {
		for (int j=i+1; j<n; ++j) {
			for (int k=j+1; k<n; ++k) {
				if (nums[i] + nums[j] + nums[k] == 0) {
					vector<int> t;
					t.push_back(nums[i]);
					t.push_back(nums[j]);
					t.push_back(nums[k]);
					ret.push_back(t);
				}
			}
		}
	}
	return ret;
}

void printMatrix(vector<vector<int>> v) {
	for (int i=0; i<v.size(); ++i) {
		cout << "{ ";
		for (int j=0; j<v[0].size(); ++j) {
			cout << v[i][j] << " " ;
		}
		cout << " }" << endl;
	}
}

int main() {
	vector<int> v({-1, 0, 1, 2, -1, -4});
	printMatrix(threeSum(v));
	vector<int> vv({0, 0, 0, 0, 0});
	printMatrix(threeSum(vv));
	return 0;
}
