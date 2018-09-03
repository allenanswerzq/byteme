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

class Solution {
public:
  vector<Interval> merge(vector<Interval>& aa) {
  	vector<Interval> ret;
  	int n = aa.size();
  	if (n <= 0) return ret;
  	sort(aa.begin(), aa.end(), cmp);
  	Interval pre = aa[0];
  	for (int i = 1; i < n; ++i) {
  		if (pre.start <= aa[i].start && aa[i].start <= pre.end) {
  			pre.end = pre.end > aa[i].end ? pre.end : aa[i].end;
  		} else {
  			ret.push_back(pre);
  			pre = aa[i];
  		}
  	}
  	ret.push_back(pre);
  	return ret;	
  }
};

int main(int argc, char** argv) {
  return 0;
}
