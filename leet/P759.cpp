#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define SZ(x) ((int)(x).size())
#define PII pair<int, int>
#define ALL(x) (x).begin(), (x).end()
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define D(x) cerr << #x " is " << (x) << endl

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
#define INF -1e9
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