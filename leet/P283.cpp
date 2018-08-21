#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

void moveZeroes(vector<int>& nums){	
	int k=0;
	for (auto n : nums)
		if (n) nums[k++] = n;
	for (int i=k; i<nums.size(); ++i)
		nums[i] = 0;
}

int main() {
	vector<int> nums{0, 1, 0, 3, 12};
	moveZeroes(nums);
	for (auto v: nums)
		cout << v << "\n";
}
