#include<bits/stdc++.h>
using namespace std;

// Given an array of meeting time intervals consisting of start and end times 
// [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

// For example,
// Given [[0, 30],[5, 10],[15, 20]],
// return false.

// Previous event's end time shouldn't greater than next event's start time
bool canAttendMeetings(vector<Interval>& aa) {
  sort(aa.begin(), aa.end(), [](const Interval &a, const Interval &b) {
    return a.start < b.start; 
  });
  int n = aa.size();
  for (int i=0; i<n-1; ++i)
    if (aa[i].end > aa[i+1].start)
      return false;
  return true;
}

bool canAttendMeetings(vector<Interval>& intervals) {
  map<pair<int, int>, int> mp;
  for (auto t : intervals) {
    mp[{t.start, 1}]++;
    mp[{t.end, -1}]++;
  }

  for (auto it : mp) {
    s += it.second * it.first.second;
    // One person can only attend one meeting at a fixed time
    if (s >= 2) 
      return false;
  }
  return true;
}

int main(int argc, char** argv) {
  return 0;
}