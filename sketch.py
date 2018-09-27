#!/usr/bin/env python
"""Generate files skeleton for my algorithm practice."""

import os
import sys

usage = """\
Usage: skeleton type name
"""

def build_cpp(fn):
  name = fn[0:-4] + "-input.txt"
  cpp2 = """\
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define outret(val) cout << (val) << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl
#define pvi(x) cout << #x << ": "; fora(a, x) cout << a << " "; cout << endl
#define par(x, n) cout<< #x << ": "; fori(a, 0, n) cout<<x[a]<<" "; cout <<endl

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args>
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ',');
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...);
}

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// #define LOCAL_FILE

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed;

#ifdef LOCAL_FILE
  // freopen(\"""" + name + """\", "rt", stdin);
  clock_t begin = clock();
#endif

  int t; cin >> t >> ws;
  fori (i, 1, t + 1) {

  }

#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cout << "elapsed(s): " << elapsed << endl;
#endif

  return 0;
}
"""
  return cpp2

def generate_file(file_name):

  if os.path.isfile(file_name):
    print("File already exists")
    cmd = "subl " if sys.platform == "darwin" else "subl "
    os.system(cmd + file_name)
    return

  with open(file_name, 'w') as f:
    cmd = "subl "
    cpp = build_cpp(file_name);
    f.write(cpp)
    print("=>Writing to {}".format(file_name))

  name = file_name[0: -4]
  os.system(cmd + 'Makefile')
  os.system('touch true-' + name + '.txt')
  os.system(cmd + ' true-' + name + '.txt')
  os.system('touch in-' + name +'.txt')
  os.system(cmd + ' in-' + name + '.txt')
  os.system(cmd + file_name)

  os.system("run_algo")


def generate_makefile(fn):
  print(fn)
  name = fn[0:-4]

  makefile = """\
#!/bin/bash
all: compile run

compile:
\t@echo
\t@echo default directory: $(shell pwd)
\t@echo
\tg++ -o elf """ + fn + """ --std=c++11 -O2

run:
\t@chmod +x ./elf
\t./elf

test: compile
\t@chmod +x ./elf
\tsplit_samples in-""" + name + """.txt
\trun_samples in-""" + name + """.txt
\t@echo
\tdiff -y result.txt true-""" + name + """.txt -W 100 | sed 's/ /-/g'

clean:
\trm ./elf
"""

  with open('Makefile', 'w') as f:
    f.write(makefile)

if __name__ == "__main__":
  if len(sys.argv) < 3:
    print(usage)
  else:
    # Generate data input file.
    print('=>Creating Makefile..')
    file_type = sys.argv[1]
    file_name = sys.argv[2]
    generate_makefile(file_name)
    generate_file(file_name)

