/* created   : 2020-10-03 15:06:50
 * accepted  : 2020-10-03 19:50:21
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

struct Node {
  int x, y, e;
  bool operator<(const Node& o) const {
    if (x == o.x) {
      if (y == o.y) {  // sort left edge before right edge
        return e < o.e;
      }
      return y < o.y;
    } else {
      return x < o.x;
    }
  }
  friend ostream& operator<<(ostream& os, const Node& n) {
    return os << "{" << n.x << " " << n.y << " " << n.e << "}";
  }
};

class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& B) {
    vector<Node> sweep;
    for (auto& it : B) {
      // NOTE: for y value, we want it appears as early as possible for left
      // edge, as later as possible for right edge.
      sweep.push_back(Node{it[0], -it[2], -1});
      sweep.push_back(Node{it[1], it[2], 1});
    }
    sort(sweep.begin(), sweep.end());
    // trace(sweep);
    vector<vector<int>> ans;
    multiset<int> height;
    int max_height = 0;
    height.insert(0);
    for (int i = 0; i < sweep.size(); i++) {
      Node n = sweep[i];
      // trace(i, n, height, max_height, ans);
      n.y = abs(n.y);
      if (n.e == -1) {
        height.insert(n.y);
        int val = *height.rbegin();
        if (max_height < val) {
          max_height = val;
          ans.push_back({n.x, n.y});
        }
      } else {
        height.erase(height.find(n.y));
        int val = *height.rbegin();
        if (val < max_height) {
          max_height = val;
          ans.push_back({n.x, val});
        }
      }
    }
    return ans;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

vector<vector<int>> test(vector<vector<int>> B) {
  Solution sol;
  auto ans = sol.getSkyline(B);
  trace(ans);
  return ans;
}

void solve() {
  EXPECT(test({{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}}),
         vector<vector<int>>(
             {{2, 10}, {3, 15}, {7, 12}, {12, 0}, {15, 10}, {20, 8}, {24, 0}}));

  EXPECT(test({{0, 2, 3}, {1, 2, 3}, {2, 5, 3}}),
         vector<vector<int>>({{0, 3}, {5, 0}}));

  EXPECT(test({{1, 2, 1}, {1, 2, 2}, {1, 2, 3}}),
         vector<vector<int>>({{1, 3}, {2, 0}}));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
