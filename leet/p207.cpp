#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pair<int, int>>

// TODO
class Solution1 {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vvi graph(numCourses, vi(0));
    vi in(numCourses, 0);
    for (auto a : prerequisites) {
      graph[a[1]].push_back(a[0]);
      ++in[a[0]];
    }
  
    deque<int> dq;
    for (int i = 0; i < numCourses; ++i) {
      if (in[i] == 0) dq.push_back(i);
    }

    while (!dq.empty()) {
      int t = dq.front(); dq.pop_front();
      for (auto a : graph[t]) {
        --in[a];
        if (in[a] == 0) dq.push_back(a);
      }
    }

    for (int i = 0; i < numCourses; ++i) {
      if (in[i] != 0) return false;
    }
    return true;
  }
};

class Solution2 {
public:
  bool dfs(int n, vpii& aa, vi& color) {
    if (color[n] == 2) return true;
    if (color[n] == 1) return false;
    if (color[n] == 0) {
      color[n] = 1;
      for (auto pair : aa) {
        if (pair.second == n)
          if(!dfs(pair.first, aa, color))
            return false;
      }
      color[n] = 2;
    }
    return true;
  }

  bool canFinish(int numCourses, vpii& aa) {
    vi color(numCourses, 0);           
    for (int i = 0; i < numCourses; ++i)
      if (color[i] == 0) {
        if (!dfs(i, aa, color))
          return false;
      }
    return true;
  }
};


class Solution {
public:
  vector<vector<int>> gg;
  vector<int> visit;
  void makeGraph(int n, vpii& pre) {
    gg.resize(n);
    visit.resize(n);
    for (auto p: pre) {
      gg[p.second].push_back(p.first);
    }
  }

  // Check whether there is a cycle exists if we staring from node `i`
  bool dfs(int i) {
    // If we already seen this node, cycle exists.
    if (visit[i] == 1) return 1;
    visit[i] = 1;
    for (auto nxt : gg[i]) {
      if (dfs(nxt)) return 1;
    }
    visit[i] = 0;

   return 0;
  }

  bool canFinish(int numCourses, vector<pair<int, int>>& pre) {
    makeGraph(numCourses, pre); 
    for (int i = 0; i < numCourses; ++i) {
      if (dfs(i)) return 0;
    }
    return 1;
  }
};

void test(int kk, vpii aa) {
  Solution go;
  bool ret = go.canFinish(kk, aa);
  output(1, ret);
}

int main(int argc, char** argv) {
  test({{0, 1}, {0, 2}, {1, 2}});
  return 0;
}
