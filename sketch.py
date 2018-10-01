#!/usr/bin/env python
"""Generate a file skeleton for my algorithm practice."""

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
#define pend cout << endl
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define outret(v) cout << (v) << endl
#define output(ix, v) cout << "Case #" << (ix) << ": " << (v) << endl
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if(v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

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
typedef vector<ll> vl;
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

def generate_file(fn):

  if os.path.isfile(fn):
    print("File already exists")
    cmd = "subl " if sys.platform == "darwin" else "subl "
    os.system(cmd + fn)
    return

  with open(fn, 'w') as f:
    cmd = "subl "
    cpp = build_cpp(fn);
    f.write(cpp)
    print("=>Writing to {}".format(fn))

  name = fn[0: -4]
  os.system('touch true-' + name + '.txt')
  os.system('touch in-' + name +'.txt')
  os.system(cmd + 'Makefile')
  os.system(cmd + ' true-' + name + '.txt')
  os.system(cmd + ' log-' + name + '.txt')
  os.system(cmd + ' in-' + name + '.txt')
  os.system(cmd + fn)
  os.system("run_algo")


def generate_makefile(fn):
  makefile = (
      '#!/bin/bash\n'
      'all: compile run\n'
      'compile:\n'
      '\t@echo\n'
      '\t@echo default directory: $(shell pwd)\n'
      '\t@echo\n'
      '\tg++ -o elf {0} --std=c++11 -O2\n'
      '\n'
      'run:\n'
      '\t@chmod +x ./elf\n'
      '\t./elf\n'
      '\n'
      'test: compile\n'
      '\t@chmod +x ./elf\n'
      '\tsplit_samples in-{1}.txt\n'
      '\trun_samples in-{1}.txt | tee log-{1}.txt\n'
      '\t@echo\n'
      '\tdiff -y result.txt true-{1}.txt -W 100 | sed "s/ /-/g"\n'
      '\n'
      'clean:\n'
      '\trm ./elf\n').format(fn, fn[0:-4])

  with open('Makefile', 'w') as f:
    f.write(makefile)

if __name__ == "__main__":
    print('=>Creating Makefile..')
    file_name = sys.argv[1]
    generate_makefile(file_name)
    generate_file(file_name)

