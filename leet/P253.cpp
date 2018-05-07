#include <cstdio>
#include <stdio.h> // for using printf
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <tuple>
#include <deque>
#include <stack>
#include <sstream>  // std:istringstream
#include <queue>
#include <iterator>

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

// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] 
// find the minimum number of conference rooms required.
int minMeetingRooms(vector<Interval>& intervals) {
  map<pair<int,int>> mp;
  for (auto t : intervals) {
    mp[{t.start, 1}]++;
    mp[{t.end, -1}]++;
  }
  int rooms = 0;
  for (auto it : mp) {
    // how many meetings are running at this time point
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
  priority_queue<int, std::vector<int>, std::greater<int>> pq;  // min heap
  pq.push(intervals[0].end); 
  for (int i=1; i<(int)intervals.size(); ++i) {
    if (pq.top() <= intervals[i].start)    // we dont need a new room 
      pq.pop();
    pq.push(intervals[i].end);
    rooms = max(rooms, (int)pq.size());
  }
  return rooms;
}