#include<bits/stdc++.h>
using namespace std;

class TurntableService {
public:
  // Use one bit to denote whether ith person is served, since there are at most
  // 15 people, so we use 1<<15 here. The 2nd dimenson denotes how foods put in
  // front of people. One number can denotes one possible state. i.e
  // 0 <0 1 2>
  // 1 <1 2 0>
  // 2 <2 0 1>
  // So dist[x][y] denotes how much time for serving x people
  // when foods arrangement is y.
  // And our answer for this problem should be the minimum number of the last
  // row of dist.
  // Also note at the beginning, the foods arrangement is 0, so like <0 1 ... n>
  int dist[1<<15][15];
  int n;
  int allServed;
  vector<set<int>> likes;
  int calculateTime(vs aa);
  int helper(int served, int pos);
};

int TurntableService::helper(int served, int pos) {
  if (served == allServed) return 0;
  int best = dist[served][pos];
  if (best >= 0) return best;

  best = 0x30303030;
  fori (r, 0, n) {
    int rotate_times = 0;
    // We can rotate to the same food position in the clockwise direction or
    // in the opposite direction.
    if (r > 0) rotate_times = 1 + min(r, n - r);
    int rotate_pos = r;

    int new_served = served;
    fori (i, 0, n) {
      int food = (rotate_pos + i) % n;
      if (likes[i].count(food))
        new_served |= (1 << i);
    }

    // Served new people
    if (new_served != served)  {
      int res = helper(new_served, r) + rotate_times + 15;
      if (res < best) {
        best = res;
        dist[served][pos] = best;
      }
    }
  }
  return best;
}

int TurntableService::calculateTime(vs aa) {
  mst(dist, -1);
  n = sz(aa);
  likes = vector<set<int>>(n, set<int>());
  allServed = (1 << n) - 1;
  fori (i, 0, n) {
    istringstream iss(aa[i]); int x;
    while (iss >> x) likes[i].insert(x);
  }
  return helper(0, 0);
}

void test(vs aa) {
  TurntableService go;
  int r = go.calculateTime(aa);
  output(r);
}

int main() {
  test({"0 2", "1", "0 1"});
  return 0;
}
