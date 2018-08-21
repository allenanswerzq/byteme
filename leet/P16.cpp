#include<bits/stdc++.h>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end()); // already sorted

	int n = nums.size();
	int distance = INT_MAX;
	int result = 0;
	for (int i=0; i<n-2; ++i) {
		if (i>1 && nums[i] == nums[i-1]) continue;
		int a = nums[i];
		int low = i+1;
		int high = n-1;
		while (low < high) {
			int b = nums[low];
			int c = nums[high];
			int sum = a + b +c; 
			if (sum - target == 0) {
				return target;
			} else {
				if (abs(sum - target) < distance) {
					distance = abs(sum - target);
					result = sum;
				}	
				
				if (sum > target) {
					// cause array already sorted. i need to decrease sum to more closer to target
					while (high>0 && nums[high] == nums[high-1]) high--;
					high--;	
				} else {
					while (low<n-1 && nums[low] == nums[low+1]) ++low;
					++low;
				}
			}
		}
	}
	return result;
}

int threeSumClosest1(vector<int>& N, int target) {
	int n = N.size();
	int ans = INT_MAX;
	int ret = 0;
	sort(N.begin(), N.end());
	for (int i=0; i<n-2; ++i) {
		if (i>1 && N[i] == N[i-1]) continue;
		for (int j=i+1; j<n-1; ++j) {
			for (int k=j+1; k<n; ++k) {
				int a = N[i];
				int b = N[j];
				int c = N[k];
				if (abs(a+b+c - target) <= ans) {
					ans = abs(a+b+c - target);
					//cout << ans << " ";
					ret = a+b+c;
				}
			}
		}
	}
	return ret;
}

int main() {
	vector<int> v({-1,2, 1, -4});
	cout << threeSumClosest(v, 1) << endl;
	vector<int> vv({-4,-7,-2,2,5,-2,1,9,3,9,4,9,-9,-3,7,4,1,0,8,5,-7,-7});
	cout << threeSumClosest(vv, 29) << endl;
	return 0;
}
