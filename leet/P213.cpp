#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha iaasadaigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <tuple>
#include <queue>
#include <deque>
#include <stack>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

int robber(vector<int>& nums, int lo, int hi) {
	int pre=0, cur=0;
	for (int i=lo; i<=hi; ++i) {
		int t = max(pre+nums[i], cur);
		pre = cur;
		cur = t;
	}
	return cur;
}

int rob(vector<int>& nums) {
	int n = nums.size();
	if (n < 2) return n ? nums[0]: 0;
	return max(robber(nums, 0, n-2), robber(nums, 1, n-1)); 
}

int main(int argc, char** argv) {
    return 0;
}
