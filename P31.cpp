#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& A) {
	int n = A.size();
	int minIdx;
   	for (int i=n-2; i>=0; --i) {
		if (A[i] < A[i+1]) {
			int minIdx = i+1;
			for (int j=i+2; j<n; ++j) 
				if (A[j] > A[i] && A[j] < A[minIdx])
					minIdx = j;
			swap(A[i], A[minIdx]);
			sort(A.begin()+i+1, A.end());
			return;
		}
	}	
	sort(A.begin(), A.end());	
}

void printVector(vector<int> v) {
	cout << "[";
	for (int x : v) 
		cout << x << " ";
	cout << "]" << endl;
}
int main() {
	vector<int> v({1,3,2});
	vector<int> vv({3,2,1});
	vector<int> vvv({1,1,5});
	nextPermutation(v);
	nextPermutation(vv);
	nextPermutation(vvv);
	printVector ( v );
	printVector ( vv );
	printVector ( vvv );
	return 0;
}
