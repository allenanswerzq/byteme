#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> ret;
	if (nums.size() < 4) return ret;
	sort(nums.begin(), nums.end());
	int n = nums.size();
	for (int i=0; i<n; ++i) {
		if (i>0 && nums[i] == nums[i-1]) continue;
		int sum = target - nums[i];
		for (int j=i+1; j<n-2;) {
			int a = nums[j];
			int start = j+1;
			int end = n-1;
			while (start < end) {
				int b = nums[start];
				int c = nums[end];
				if (a+b+c == sum) {
					vector<int> t;
					//cout << nums[i] << endl;
					t.push_back(nums[i]);
					t.push_back(a);
					t.push_back(b);
					t.push_back(c);
					ret.push_back(t);
					while (start<n-1 && nums[start] == nums[start+1]) ++start;
					while (end>0 && nums[end] == nums[end-1]) --end;
					++start;
					--end;
				} else if (a+b+c > sum){
					// while (end>0 && nums[end] == nums[end-1]) --end;
					--end;
				} else {
					// while (start<n-1 && nums[start] == nums[start+1]) ++start;
					++start;
				}
			}
			while(j<n-2 && nums[j] == nums[j+1]) ++j;
			++j;
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
	vector<int> v({-1,0,1,2,-1,-4});
	printMatrix( fourSum(v, -1) );
	return 0;
}
