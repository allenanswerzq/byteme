#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	if (nums.size() <= 0) return 0;
	int k = 0;
/*	for (int i=0; i<nums.size();) {
		while (i>0 && i<nums.size() && nums[i] == nums[i-1]) ++i; 
		if (i<nums.size())
			nums[k++] = nums[i++];
	}
	*/
	/*for (int i=0; i<nums.size(); ++i) {
		if (i>0 && nums[i] == nums[i-1]) continue;
		nums[k++] = nums[i];
	}*/
	for (int i=0; i<nums.size()-1; ++i) {
		if (nums[i] != nums[i+1])
			nums[++k] = nums[i+1];
	}
	return k+1;	
}

void printVector(vector<int> nums, int k) {
	cout << "[";
	for(int i=0; i<k; ++i) {
		cout << nums[i] << " ";
	}
	cout << "]" << endl;
}

int main(){
	vector<int> v({1, 1, 1, 1, 2, 2, 3, 3 });
	int n = removeDuplicates(v);
	cout << n << endl;
	printVector(v, n);
	return 0;
}
