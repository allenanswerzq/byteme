#include <bits/stdc++.h>
using namespace std;

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
    int n = sz(schedule);
    vector<Interval> ret;
    vector<pii> pp;
    for (auto s: schedule) {
      for (auto e: s) pp.PB(MP(e.start, e.end));
    }
    sort(all(pp));
      int lo = inf;
      for (auto p: pp) {
        if (lo<p.first && lo!=inf)
          ret.pb(Interval(lo, p.first));
        lo = max(lo, p.second);
      }
    return ret;
  }
};
