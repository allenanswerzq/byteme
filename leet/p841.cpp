#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int res;
int visit[1010];
vvi rooms;

void dfs(int start) {
  if (!visit[start]) {
    visit[start] = 1;
    ++res;
    fora(key, rooms[start]) 
      dfs(key);
  }
}

class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>>& aa) {
    int n = sz(aa);
    res = 0;
    rooms = aa;
    mst(visit, 0);
    dfs(0);
    return res == n;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
