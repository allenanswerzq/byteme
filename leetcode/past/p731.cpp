#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
public:
  map<pair<int, int>> mp; // we must need ordered map to sort start time
  MyCalendarTwo() {

  }

  bool book(int start, int end) {
    m[{end, -1}]++; // end time counter plus 1
    m[{start,1}]++; // start time counter plus 1
    // mp is sorted according to start time of events
    int cnt = 0;
    for (auto it : mp){
      cnt += it.second * it.first.second; // current total book counter
      if (cnt >= 3) { // triple book occurs
        // remove this one from mp
        m[{end, -1}]--;
        m[{start,1}]--;
        return false; // this event can not be booked
      }
    }
    return true;
  }

};
