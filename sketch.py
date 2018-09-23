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

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define outret(val) cout << (val) << endl;
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define pvi(x) fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl

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
  freopen(\"""" + name + """\", "rt", stdin);
  clock_t begin = clock();
#endif

  int t; cin >> t >> ws;
  fori (i, 1, t + 1) {

  }

#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
#endif

  return 0;
}
"""

  cpp = """\
#include<bits/stdc++.h>
using namespace std;

#define bk back
#define fi first
#define fr front
#define se second
#define mk make_pair
#define inf INT_MAX
#define nnf INT_MIN
#define dist distance
#define null nullptr
#define ll long long
#define ld long double
#define ull unsigned ll
#define uset unordered_set
#define umap unordered_map

#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>
#define vs vector<string>
#define pll pair<ll, ll>
#define pii pair<int, int>

#define sz(x) ((int)(x).size())
#define vpii vector<pair<int,int>>
#define judge(a, b) assert((a) == (b))
#define all(x) (x).begin(), (x).end()
#define xpq priority_queue<int, vi>
#define mpq priority_queue<int, vi, greater<int>>
#define mst(x, y) memset(x, y, sizeof(x))
#define rall(x) (x).rbegin(), (x).rend()
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define pvi(x) cout << #x << ": "; fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl

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

const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// #define LOCAL_FILE

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed;

#ifdef LOCAL_FILE
  freopen(\"""" + name + """\", "rt", stdin);
  clock_t begin = clock();
#endif


  int t; cin >> t;
  fori (i, 1, t + 1) {

  }

#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
#endif
  return 0;
}
"""
  return cpp2;

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
\trun_samples in-""" + name + """.txt
\t@echo
\tcolordiff -y result.txt true-""" + name + """.txt -W 100

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

