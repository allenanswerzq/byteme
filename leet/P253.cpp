#include<bits/stdc++.h>
using namespace std;

// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] 
// find the minimum number of conference rooms required.

// TODO
int minMeetingRooms(vector<Interval>& intervals) {
  map<pair<int,int>> mp;
  for (auto t : intervals) {
    mp[{t.start, 1}]++;
    mp[{t.end, -1}]++;
  }
  int rooms = 0;
  for (auto it : mp) {
    // How many meetings are running at this time point
    s += it.second * it.first.second;     
    rooms = max(rooms, s);
  }
  return rooms;
}

// Use priority queue as min heap
static cmp(const Interval &a, const Interval &b) {
 return a.start < b.start;  
}

int minMeetingRooms(vector<Interval>& intervals) {
  sort(intervals.begin(), intervals.end(), cmp);
  int rooms = 1;
  // Min heap
  priority_queue<int, std::vector<int>, std::greater<int>> pq;  
  pq.push(intervals[0].end); 
  for (int i=1; i<(int)intervals.size(); ++i) {
    // We dont need a new room
    if (intervals[i].start >= pq.top())     
      pq.pop();
    pq.push(intervals[i].end);
    rooms = max(rooms, (int)pq.size());
  }
  return rooms;
}

int main(int argc, char** argv) {
  return 0;
}