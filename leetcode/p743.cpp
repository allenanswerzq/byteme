#include<bits/stdc++.h>
using namespace std;


// Idea: get shortest path from source vertex to each vertex
// Maximum shortest path of all these path is the result we needed

int networkDelayTime(vvi& times, int n, int s) {
  int inf = 1e9, N = 101;
  vi dist(N, inf), visit(N, 0);
  unordered_map<int, vector<pii>> mp;
  for (auto t : times) mp[t[0]].push_back(make_pair(t[1], t[2]));
  dist[s] = 0;
  queue<int> dq;
  dq.push(s);
  while (!dq.empty()) {
    int x = dq.front(); dq.pop();
    for (auto e : mp[x]) {
      int y = e.first;
      int w = e.second;
      int new_dist = dist[x] + w;
      if (new_dist < dist[y]) {
        dist[y] = new_dist;
        dq.push(y);
      }
    }
  }
  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    if (dist[i] >= inf) return -1;
    mx = max(mx, dist[i]);
  }
  return mx;
}
