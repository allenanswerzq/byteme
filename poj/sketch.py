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
