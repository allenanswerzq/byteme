#!/usr/bin/env python
"""Generate files skeleton for my algorithm practice."""

import os
import sys

usage = """\
Usage: skeleton type name
"""

cpp = """\
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PII pair<int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define D(x) cerr << #x " is " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
"""

py = """\
#!/usr/bin/env python

"""
def generate_file(file_type, file_name):

    if os.path.isfile(file_name):
        print("File already exists")
        cmd = "subl " if sys.platform == "darwin" else "subl "
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
