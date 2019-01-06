#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
private:
  vector<pair<int, int>> books;
public:
  MyCalendar() {
  }

  bool book(int start, int end) {
    for (auto p : books) {
      if (max(p.first, start) < min(p.second, end))
        return false;
    }
    books.push_back({start, end});
    return true;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
