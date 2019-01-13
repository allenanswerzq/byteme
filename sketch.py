#!/usr/bin/env python3
"""Generate a file skeleton for my algorithm practice."""

# TODO(landcold7): this file is really ugly, need to rewrite someday.
# TODO(landcold7): rewrite makefile generating, make it more professional.

import os
import sys

def build_cpp():
  cpp = '''\
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pend cout << '\\n'
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(v) cout << (v) << '\\n'
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\\n'
#define pvi(x, v) if (v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if (v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
    cout << fixed << name << ": " << arg << '\\n';
}

template <typename T, typename... Args>
void _f(const char* names, T&& arg, Args&&... args) {
    const char* split = strchr(names + 1, ',');
    cout.write(names, split - names) << ": " << arg << " |";
    _f(split, args...);
}

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve() {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {

    }
    return 0;
}
'''

  return cpp

def generate_file(fn):

  if os.path.isfile(fn):
    print("File already exists")
    cmd = "subl " if sys.platform == "darwin" else "subl "
    os.system(cmd + fn)
    return

  with open(fn, 'w') as f:
    cmd = "subl "
    cpp = build_cpp();
    f.write(cpp)
    print("=>Writing to {}".format(fn))

  name = fn[0: -4]
  make = 'Makefile-' + name

  os.system('touch in-' + name +'.txt')
  os.system('mv Makefile ' + make)
  os.system(cmd + make)
  os.system(cmd + ' comp-' + name + '.cpp')
  os.system(cmd + ' gen-' + name + '.cpp')
  os.system(cmd + ' true-' + name + '.txt')
  os.system(cmd + ' in-' + name + '.txt')
  os.system(cmd + fn)
  os.system('algo-make test ' + make)


def generate_makefile(fn):
  makefile = (
      '#!/bin/bash\n'
      'all: run\n'
      'compile:\n'
      '\t@echo default directory: $(shell pwd)\n'
      '\t@echo\n'
      '\tg++ -o elf {0}.cpp --std=c++11 -O2 -Wall\n'
      '\n'
      'run: clean compile\n'
      '\t@chmod +x ./elf\n'
      '\t./elf\n'
      '\n'
      'test: clean compile\n'
      '\t@chmod +x ./elf\n'
      '\talgo-split in-{0}.txt\n'
      '\talgo-run result.txt | tee log-{0}.txt\n'
      '\t@echo "====================" \n'
      '\tdiff -y result.txt true-{0}.txt\n'
      '\n'
      'comp: comp-{0}.cpp\n'
      '\tg++ -o elf comp-{0}.cpp --std=c++11 -O2 -Wall\n'
      '\talgo-split in-{0}.txt\n'
      '\talgo-run comp-result.txt | tee comp-{0}.txt\n'
      '\tdiff -y result.txt comp-result.txt\n'
      '\trm comp-result.txt\n'
      '\n'
      'gen: gen-{0}.cpp\n'
      '\t@echo "Generating test data.."\n'
      '\t@g++ -O2 -std=c++11 -DJNGEN_DECLARE_ONLY gen-{0}.cpp -o gen -ljngen -lgvc -lcgraph\n'
      '\t./gen | tee in-{0}.txt\n'
      '\t@rm gen\n'
      '\n'
      'clean:\n'
      '\t@rm -f ./elf input_* log_* result.txt\n').format(fn[0:-4])

  with open('Makefile', 'w') as f:
    f.write(makefile)

if __name__ == "__main__":
    print('=>Creating Makefile..')
    file_name = sys.argv[1]
    generate_makefile(file_name)
    generate_file(file_name)
    # sys.exit(0)

