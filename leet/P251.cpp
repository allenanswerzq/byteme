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

class Vector2D {
    vector<vector<int>>::iterator row_it, row_end;
    vector<int>::iterator col_it;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        row_it = vec2d.begin();
        row_end = vec2d.end();
        while(row_it!=row_end && row_it->empty()) row_it++;
        if(row_it!=row_end) col_it = row_it->begin();
    }

    int next() {
        int v = *col_it;
        col_it++;
        if(col_it==row_it->end()){
            row_it++;
            while(row_it!=row_end && row_it->empty()) row_it++; // skip empty rows
            if(row_it!=row_end) col_it = row_it->begin();
        }
        return v;
    }

    bool hasNext() {
       if(row_it==row_end) return false;
       return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 *
 /
