#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
// 10^9
class Solution {
public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
  	int n = SZ(schedule);
  	vector<Interval> ret;
  	vector<PII> pp;
  	for (auto s: schedule) {
  		for (auto e: s) pp.PB(MP(e.start, e.end));
  	}
  	sort(ALL(pp));
   		int lo = INF; 
   		for (auto p: pp) {
   			if (lo<p.first && lo!=INF)
   				ret.PB(Interval(lo, p.first));
   			lo = max(lo, p.second);
   		}	
   	return ret;
  }
};
