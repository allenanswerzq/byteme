#include <cstdio>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
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

// Max heap
int findKthLargest(vector<int>& nums, int k) {
	priority_queue<int> pq(nums.begin(), nums.end());
	while (--k > 0) pq.pop();
	return pq.top();
}

// MultiSet
int findKthLargest(vector<int>& nums, int k) {
	multiset<int> mset(nums.begin(), nums.end());
	int i=1;
	for (auto it=mset.rbegin(); it!=mset.rend(); ++it) {
		if (i++ >= k)
			return *it;
	}
	return 0;
}

// Divide and conquer
int partition(vector<int>& nums, int l, int r) {
}

int findKthLargest(vector<int>& nums, int k) {

}

int main(int argc, char** argv) {

    return 0;
}
