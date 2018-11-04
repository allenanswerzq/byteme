#include<bits/stdc++.h>
using namespace std;

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

int main() {
  return 0;
}
