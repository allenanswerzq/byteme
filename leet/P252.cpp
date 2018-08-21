#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  printf("[ ");
  for (auto x:v)
      printf("%d ", x);
  printf("]\n");
}

void printMatrix(vector<vector<int>>& v) {
  printf("{\n");
  for (auto x:v)
    printVector(x);
  printf("}\n");
}

bool isPowerOfTwo(int x) {
  //return (x && !(x & (x-1)));
  return x* !(x&(x-1)) > 0;
}

int countOne (int n){
  while( n ){
    n = n&(n-1);
    count++;
  }
  return count;
}

char toupper( char a ) {
  return ((a >= 'a' && a <= 'z') ? a-('a'-'A') : a );
}

int main(int argc, char** argv) {
  return 0;
}

// Previous event's end time shouldn't greater than next event's start time
bool canAttendMeetings(vector<Interval>& intervals) {
  sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
   return a.start < b.start; 
  });
  int n = intervals.size();
  for (int i=0; i<n-1; ++i)
    if (intervals[i].end > intervals[i+1].start)
      return false;
  return true;
}

bool canAttendMeetings(vector<Interval>& intervals) {
  map<pair<int,int>> mp;
  for (auto t : intervals) {
    mp[{t.start, 1}]++;
    mp[{t.end, -1}]++;
  }
  for (auto it : mp) {
    s += it.second * it.first.second;
    if (s >= 2) // One person can only attend one meeting at fixed time
      return false;
  }
  return true;
}
