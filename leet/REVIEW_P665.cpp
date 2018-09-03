#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
  cout << x << " ";
  cout <<"] " << endl;
}

bool checkPossibility(vector<int>& nums) {
	int n = nums.size();
	int mark = 0;
	for (int i=0; i<n-1; ++i)
		if (nums[i] > nums[i+1]) {
  mark++;
			if (i==0 || nums[i-1] > nums[i+1])
  nums[i+1] = nums[i];
  else 
  nums[i] = nums[i-1];
  }
  return mark<=1;
}


int main(int argc, char** argv) {
  return 0;
}
