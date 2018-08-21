#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
      cout << x << " ";
    cout <<"] " << endl;
}

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval>& A) {
	vector<Interval> res;
	int n = A.size();
	if (n <= 0) return res;
	sort(A.begin(), A.end(), [](const Interval& a, const Interval& b) {
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

int main(int argc, char** argv) {
    return 0;
}
