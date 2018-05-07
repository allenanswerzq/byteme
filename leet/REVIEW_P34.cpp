#include <cstdio>  
#include <iostream>
#include <cstdlib>
#include <algorithm> //lower_bound upper_bound equal_range
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;
# Three approachs to solve this problem
# Approach #1 binary_search
# Approach #2 find left and right bound
		   #2 also use standard library
# Approach #3 divide and conquer

vector<int> searchRange1(vector<int>& A, int target) {
	int n = A.size();
	int left = 0, right = n-1;
	vector<int> ret;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (A[mid] == target) {
			int i = mid;
			while (i>0 && A[i] == A[i-1]) --i;
			ret.push_back(i);
			i = mid;
			while (i<n && A[i] == A[i+1]) ++i;
			ret.push_back(i);
			return ret;
		}else if (A[mid] > target) {
			right = mid - 1;
		}else{
		   	left = mid + 1;
		}
	}
	return vector<int>({-1, -1});
}

printVector(vector<int>& v) {
	cout << "[";
	for (int x:v)
		cout << x << " ";
	cout <<"]" << endl;
}
// NOTE
int search1(vector<int> A, int target) {
		int low = 0, high = A.size();
		while (low < high) {
			int mid = low + ((high - low) >> 1);
			//low <= mid < high
			if (A[mid] < target) {
				low = mid + 1;
			} else {
				//should not be mid-1 when A[mid]==target.
				//could be mid even if A[mid]>target because mid<high.
				high = mid;
			}
		}
		return low;
}

int main(int argc, char** argv) {
	int n[] = {0,0,2,3,4,4,4,5};
	vector<int> v(n, n + sizeof(n)/sizeof(int));
	//vector<int> ret = searchRange(v, 5);
	//printVector(ret);
	int x = 0;
	if (argc > 1)
		x = atoi(argv[1]);
	cout << search(v, x);
    return 0;
}
