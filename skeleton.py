#!/usr/bin/env python
"""Generate files skeleton for my algorithm practice."""

import os
import sys

usage = """\
Usage: skeleton type name 
"""

cpp = """\
#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (int x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

int main(int argc, char** argv) {
    return 0;
}
"""

def generate_file(file_type, file_name):
    if os.path.isfile(file_name):
        print("File already exists")
        return
    with open(file_name, 'w') as f:
        if file_type == "cpp":
            f.write(cpp)
            print("Written to", file_name)
            os.system("gvim " + file_name)


if __name__ == "__main__":
    if len(sys.argv) < 3:
        print(usage)
    else:
        file_type = sys.argv[1]
        file_name = sys.argv[2]
        generate_file(file_type, file_name)
