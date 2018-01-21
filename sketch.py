#!/usr/bin/env python
"""Generate files skeleton for my algorithm practice."""

import os
import sys

usage = """\
Usage: skeleton type name
"""

cpp = """\
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
  printf("]\\n");
}

void printMatrix(vector<vector<int>>& v) {
  printf("{\\n");
  for (auto x:v)
    printVector(x);
  printf("}\\n");
}

bool isPowerOfTwo(int x) {
  //return (x && !(x & (x-1)));
  return x* !(x&(x-1)) > 0;
}

int countOne (int n){
  int count =0;
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
"""

py = """\
#!/usr/bin/env python

"""
def generate_file(file_type, file_name):

    if os.path.isfile(file_name):
        print("File already exists")
        cmd = "code " if sys.platform == "darwin" else "code "
        os.system(cmd + file_name)
        return
    with open(file_name, 'w') as f:
        cmd = "code "
        if file_type == "cpp":
            f.write(cpp)
            print("Written to", file_name)
            os.system(cmd + file_name)
        if file_type == "py":
            f.write(py)
            print("Written to", file_name)
            os.system(cmd + file_name)


if __name__ == "__main__":
    if len(sys.argv) < 3:
        print(usage)
    else:
        file_type = sys.argv[1]
        file_name = sys.argv[2]
        generate_file(file_type, file_name)
