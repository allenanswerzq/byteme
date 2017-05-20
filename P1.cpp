#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& a, int tar) {
		sort(a.begin(), a.end());
		vector<int> ret;
		int left = 0, right = a.size() - 1;
		while (left < right) {
			if (a[left] + a[right] == tar) {
				ret.push_back(left);
				ret.push_back(right);
				return ret;
			} else if (a[left] + a[right] < tar) left++;
			else right--;
		}
		return ret;
	}
	vector<int> twoSum2(vector<int>& a, int tar) {
		int n = a.size();
		vector<int> ret;
		map<int, int> m;
		for (int i=0; i<n; ++i) {
			if (m.find(tar - a[i]) != m.end()) {
				ret.push_back(i);
				ret.push_back(m[tar - a[i]]);
				return ret;
			} else {
				m[a[i]] = i;
			}
		}	
		return ret;
	}

	// naive sloution
    vector<int> twoSum1(vector<int>& a, int target) {
		int n = a.size();
		vector<int> ret;
    	for (int i=0; i<n; ++i) {
			for (int j=i+1; i<n; ++j)
				if (a[i] + a[j] == target) {
					ret.push_back(i);
					ret.push_back(j);
					return ret;
				}
		}	
		return ret;
    }
};

int main() 
{
	int m[] = {2, 7, 11, 15};
	vector<int> n(m, m+4);
	Solution s;
	int target = 9;
	vector<int> ans = s.twoSum(n, target);
	cout << ans[0] << " " <<  ans[1] << endl;
	return 0;
}
