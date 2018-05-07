#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>

using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<int> tuple(3,0);
	vector<vector<int>> vec_ret;

	sort(nums.begin(), nums.end());
	unordered_map<int, int> mp;

	// record the last position nums[i] appears
	for (int i = 0; i < nums.size(); ++i) {
		mp[nums[i]] = i;
	}

	int i = 0, j = 1;
	while(i < nums.size()) {
		if (nums[i] > 0) break;
		while(j < nums.size()) {
			int sum = nums[i] + nums[j];
			if (mp.find(-sum) != mp.end() && mp[-sum] > j) {
				tuple[0] = nums[i];
				tuple[1] = nums[j];
				tuple[2] = -nums[i] - nums[j];
				vec_ret.push_back(tuple);
			}
			j = mp[nums[j]] + 1; // skip duplicate
		}
		i = mp[nums[i]] + 1; // skip duplicated
		j = i + 1;
	}
	return vec_ret;
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
