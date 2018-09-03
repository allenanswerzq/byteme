#include<bits/stdc++.h>
using namespace std;




const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// TODO
// Breadth first search
class Solution {
public:
  int racecar(int goal) {
  deque<pii> q;
  // Starts from position 0 with speed 1.
  q.pb({0, 1}); 
  unordered_set<string> mp;
  for (int level = 0; sz(q); level++) {
  int n = sz(q);
  // Search each layer.
  fori (i, 0, n) {
  auto cur = q.front(); q.ppf();
  int pos = cur.fi;
  int speed = cur.se;
  if (pos == goal) return level;
  // Move one step.
  // Equivalently adding a 'A' in the control sequences.
  int n_pos = pos + speed;
  int n_speed = speed * 2;
  pii nxt = {n_pos, n_speed};
  string state = to_string(nxt.fi) + " " + 
       to_string(nxt.se);
  if (!mp.count(state) && 0 < n_pos && n_pos < 2 * goal) {
    q.pb(nxt);
    mp.insert(state); 
  }
  // Adding a new 'R' in the control sequence.
  n_pos = pos;
  n_speed = speed > 0 ? -1 : 1;
  nxt = {n_pos, n_speed};
  state = to_string(nxt.fi) + " " + 
    to_string(nxt.se);
  if (!mp.count(state) && 0 < n_pos && n_pos < 2 * goal) {
    q.pb(nxt);
    mp.insert(state); 
  }
  }    
  }
  return -1;
  }
};

void test(int n) {
  Solution go;
  int r = go.racecar(n);
  cerr(r);    
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed; 
  test(6);
  return 0;
}
