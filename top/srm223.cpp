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
#include <random>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

#define debug
#ifdef debug
#define pr(x) printf x 
#else   
#define pr(x) do { if (0) printf x; } while (0) 
#endif

#define prt printf
#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define fora(e, c) for (auto &e : c)
#define all(x) (x).begin(), (x).end()
#define mst(X, v) memset((X), (v), sizeof((X)))
#define len(X) strlen(X)
#define vi vector<int>
#define vs vector<string>
#define sz(x) ((int)(x).size())
#define pii pair<int, int>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define cerr(x) cerr << #x " is " << (x) << endl
const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int d[100000000];

class SmartWordToy {
public:
  string de_state(int state);
  int state(string s);
  bool check(string w, vs& forbid);
  set<int> init(vs& forbid);
  // map<int, int> d; // Save distance between start and finish

  int minPresses(string start, string finish, vs& forbid) {
    set<int> st = init(forbid);
    queue<int> Q;
    Q.push(state(start));
    memset(d, 100, sizeof(d));
    d[state(start)] = 0;
    while (!Q.empty()) {
      int top = Q.front(); Q.pop();
      // Reach to the finish string
      if (top == state(finish))
        return d[top];
      // Otherwise get all next states
      string curr = de_state(top);
      fori(i, 0, 4) {
        for(int j=-1; j<=1; j+=2) {
          string tmp = curr;
          // Note:
          tmp[i] = 'a' + (26 + tmp[i] - 'a' + j) % 26;
          int next_state = state(tmp);
          if (!st.count(next_state)) {
            // Note: 
            if (d[top] + 1 < d[next_state]) {
              d[next_state] = d[top] + 1;
              Q.push(next_state);
            }
          }
        }
      }
    }
    return -1;
  }
};

set<int> SmartWordToy::init(vs& forbid) {
  set<int> ff;
  vector<vs> vvs;
  fora(s, forbid) {
    istringstream iss(s);
    vs ss;
    fori(i, 0, 4) {
      string tmp;
      iss >> tmp;
      ss.pb(tmp);
    }
    vvs.pb(ss);
  }

  fora(ss, vvs) {
    fori(i, 0, sz(ss[0]))
      fori(j, 0, sz(ss[1]))
        fori(k, 0, sz((ss[2])))
          fori(h, 0, sz(ss[3])) {
            string r;
            r += ss[0][i];
            r += ss[1][j];
            r += ss[2][k];
            r += ss[3][h];
            int s = state(r);
            ff.insert(s);
          }
  }

  return ff;
}

string SmartWordToy::de_state(int state) {
  string r;
  fori(i, 0, 4) {
    char x = state & 31;
    r = (char)('a' + x) + r;
    state >>= 5;
  }
  return r;
}

int SmartWordToy::state(string s) {
  // Present a input string to a int value as a state
  int state = 0;
  fori(i, 0, 4) {
    state |= s[i]-'a';
    // Note: we only want to left shift 3 times. 
    if (i < 3)
      state <<= 5;
  }
  return state;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  SmartWordToy go;
  vs ff;
  ff.pb("bz a a a");
  ff.pb("a bz a a");
  ff.pb("a a bz a");
  ff.pb("a a a bz");

  cout << go.state("zzzz") << '\n';

  vs ft;
  cout << go.minPresses("aaaa", "zzzz", ff) << '\n';
  cout << go.minPresses("aaaa", "bbbb", ft) << '\n';
  cout << go.minPresses("aaaa", "mmnn", ft) << '\n';

  vs fa;
  fa.pb("cdefghijklmnopqrstuvwxyz a a a");
  fa.pb("a cdefghijklmnopqrstuvwxyz a a"); 
  fa.pb("a a cdefghijklmnopqrstuvwxyz a"); 
  fa.pb("a a a cdefghijklmnopqrstuvwxyz");
  cout << go.minPresses("aaaa", "zzzz", fa) << '\n';

  return 0;
}
