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
