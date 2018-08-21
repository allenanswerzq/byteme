#include<bits/stdc++.h>

using namespace std;

int removeElement(vector<int>& A, int val) {
	int k = 0;
	for (int i=0; i<A.size(); ++i) {
		if (A[i] != val) 
			A[k++] = A[i];
	}	
	return k;
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
	int n = removeElement(v, 2);
	cout << n << endl;
	printVector(v, n);
	return 0;
}
