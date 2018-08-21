#include<bits/stdc++.h>

using namespace std;

vector<Interval> merge(vector<Interval>& A) {
	vector<Interval> res;
	int n = A.size();
	if (n <= 0) return res;
	sort(A.begin(), A.end(), [] (const Interval& a, const Interval& b) {
			return a.start < b.start;});
	Interval prev = A[0];
	for (int i=1; i<n; ++i) {
		if (prev.start<=A[i].start && A[i].start<=prev.end) {
			prev.end = prev.end > A[i].end ? prev.end : A[i].end;
		} else {
			res.push_back(prev);
			prev = A[i];
		}
	}
	res.push_back(prev);
	return res;	
}

// obviously. not a prefect approach
// but it accepted
vector<Interval> insert(vector<Interval>& A, Interval a) {
	A.push_back(a);
	return merge(A);
}

int main(int argc, char** argv) {
    return 0;
}
