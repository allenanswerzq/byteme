#!/usr/bin/env python
"""Generate files skeleton for my algorithm practice."""

import os
import sys

usage = """\
Usage: skeleton type name
"""

cpp = """\
#include <set>
#include <map>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <vector>
#include <random>
#include <cstdio>
#include <string>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <climits>
#include <cassert>
#include <fstream>
#include <sstream>
#include <numeric>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf pop_front
#define ppb pop_back
#define mb emplace_back
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int, int>

#define len(x) strlen(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define cerr(x) cerr << #x " is " << (x) << endl
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)

const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
"""

# #include <unordered_map>
# #include <unordered_set>
# #include <algorithm>
# #include <iostream>
# #include <iterator>
# #include <numeric>
# #include <sstream>
# #include <fstream>
# #include <cassert>
# #include <climits>
# #include <unistd.h>
# #include <cstdlib>
# #include <cstring>
# #include <bitset>
# #include <string>
# #include <cstdio>
# #include <random>
# #include <vector>
# #include <cmath>
# #include <queue>
# #include <deque>
# #include <stack>
# #include <list>
# #include <map>
# #include <set>
# using namespace std;

# #define fori(i, a, b) for (int i=(a); i<(b); ++i)
# #define ford(i, a, b) for (int i=(a); i>(b); --i)
# #define fora(e, c) for (auto &e : c)
# #define all(x) (x).begin(), (x).end()
# #define len(x) strlen(x)
# #define vi vector<int>
# #define vs vector<string>
# #define sz(x) ((int)(x).size())
# #define pii pair<int, int>
# #define ll long long
# #define fi first
# #define se second
# #define mp make_pair
# #define pb push_back
# #define pf pop_front
# #define ppb pop_back
# #define pvi(x) fora(r, x) cout << r << ' '; cout << '\\n'
# #define cerr(x) cerr << #x " is " << (x) << endl
# #define prt(x, n) fori(i, 0, n) cout << x[i] << " "; cout << "\\n"
# #define prt2(x, n, m) fori(i, 0, n) {fori(j, 0, m) cout << x[i][j] << " "; \\
#         cout << "\\n"; } cout << "\\n"
# #define mst(x, n, v) fori(i, 0, n) x[i] = v
# #define mst2(x, n, m, v) fori(i, 0, n) fori(j, 0, m) x[i][j] = v
# #define mst3(x, n, m, c, v) \\
#         fori(i, 0, n) \\
#           fori(j, 0, m) \\
#             fori(k, 0, c) \\
#               x[i][j][k] = v
# const double eps = 1e-9;
# int cmp(double x, double y = 0, double tol = eps) {
#   return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
# }

# int main(int argc, char** argv) {
#   std::ios_base::sync_with_stdio(false);
#   return 0;
# }
py = """\
#!/usr/bin/env python
"""


def generate_file(flag, file_type, file_name):

    if os.path.isfile(file_name):
        print("File already exists")
        cmd = "subl " if sys.platform == "darwin" else "subl "
        os.system(cmd + file_name)
        return
    
    with open(file_name, 'w') as f:
        cmd = "subl "
        if file_type == "cpp":
            f.write(cpp)
            print("=>Written to {}".format(file_name))
            if flag == 'yes':
                os.system(cmd + 'Makefile')
                os.system('touch in_'+file_name[0:-4]+'.txt')
                os.system('touch true_'+file_name[0:-4]+'.txt')
                os.system(cmd + ' in_'+file_name[0:-4]+'.txt')
                os.system(cmd + ' true_'+file_name[0:-4]+'.txt')
            os.system(cmd + file_name)

        if file_type == "py":
            f.write(py)
            print("=>Written to {}".format(file_name))
            os.system(cmd + file_name)
        

def generate_makefile(file_name):
    makefile = """\
all: compile run

compile:
\tg++ -o elf """ + file_name + """ --std=c++11

run: 
\t@chmod +x ./elf
\t./elf

test: compile
\t@chmod +x ./elf
\t./elf < in_"""+ file_name[0:-4] + """.txt
\t@echo "\\n---------------------"
\t./elf < in_"""+ file_name[0:-4] + """.txt 2>&1 > out_""" + file_name[0:-4] 
    + """.txt 
\tcolordiff -y out_"""+  file_name[0:-4] + """.txt true_"""+ file_name[0:-4] 
    + """.txt -W 100

clean:
\trm ./elf
"""

    with open('Makefile', 'w') as f:
        f.write(makefile)


if __name__ == "__main__":
    if len(sys.argv) < 4:
        print(usage)
    else:
        if sys.argv[1] == 'yes':
            print('=>Creating Makefile..')
            file_type = sys.argv[2]
            file_name = sys.argv[3]
            generate_makefile(file_name)
            generate_file('yes', file_type, file_name)
        else:
            print('=>No Makefile')
            file_type = sys.argv[2]
            file_name = sys.argv[3]
            generate_file('no', file_type, file_name)

