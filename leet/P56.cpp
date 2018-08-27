#include<bits/stdc++.h>
using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(const Interval& a, const Interval& b) {
  return a.start < b.start;
}

vector<Interval> merge(vector<Interval>& aa) {
	vector<Interval> res;
	int n = aa.size();
	if (n <= 0) return res;
	sort(aa.begin(), aa.end(), cmp);
	Interval pre = aa[0];
	for (int i=1; i < n; ++i) {
		if (pre.start <= aa[i].start && aa[i].start <= pre.end) {
			pre.end = pre.end > aa[i].end ? pre.end : aa[i].end;
		} else {
			res.push_back(pre);
			pre = aa[i];
		}
	}
	res.push_back(pre);
	return res;	
}

int main(int argc, char** argv) {
  return 0;
}
