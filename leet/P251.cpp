#include<bits/stdc++.h>
using namespace std;

// Implement an iterator to flatten a 2d vector.
// For example,
// Given 2d vector =

// [
//   [1,2],
//   [3],
//   [4,5,6]
// ]

// By calling next repeatedly until hasNext returns false, 
// the order of elements returned by next should be: [1,2,3,4,5,6].

// Hint:
// How many variables do you need to keep track?
// Two variables is all you need. Try with x and y.
// Beware of empty rows. It could be the first few rows.
// To write correct code, think about the invariant to maintain. What is it?
// The invariant is x and y must always point to a valid point in the 2d vector. 
// Should you maintain your invariant ahead of time or right when you need it?
// Not sure? Think about how you would implement hasNext(). Which is more complex?
// Common logic in two different places should be refactored into a common method.
// Follow up:
// As an added challenge, try to code it using only iterators in C++ or iterators in Java.


class Vector2D {
private:
  vector<vector<int>>::iterator row_it, row_end;
  vector<int>::iterator col_it;

public:
  Vector2D(vector<vector<int>>& vec2d) {
    row_it = vec2d.begin();
    row_end = vec2d.end();
    while (row_it != row_end && row_it->empty()) ++row_it;
    if (row_it != row_end) col_it = row_it->begin();
  }

  int next() {
      int val = *col_it;
      col_it++;
      if(col_it == row_it->end()){
        row_it++;
        // Skip empty rows.
        while(row_it != row_end && row_it->empty()) ++row_it;
        if(row_it != row_end) col_it = row_it->begin();
      }
      return val;
  }

  bool hasNext() {
    return row_it == row_end;
  }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 **/

int main(int argc, char** argv) {
  return 0;
}