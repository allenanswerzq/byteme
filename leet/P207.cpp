#include<bits/stdc++.h>
using namespace std;

#define vpii vector<pair<int, int>>

// TODO
// class Solution {
// public:
//   bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//     vector<vector<int> > graph(numCourses, vector<int>(0));
//     vector<int> in(numCourses, 0);
//     for (auto a : prerequisites) {
//       graph[a[1]].push_back(a[0]);
//       ++in[a[0]];
//     }
    
//     queue<int> q;
//     for (int i = 0; i < numCourses; ++i) {
//       if (in[i] == 0) q.push(i);
//     }

//     while (!q.empty()) {
//       int t = q.front();
//       q.pop();
//       for (auto a : graph[t]) {
//         --in[a];
//         if (in[a] == 0) q.push(a);
//       }
//     }

//     for (int i = 0; i < numCourses; ++i) {
//       if (in[i] != 0) return false;
//     }
//     return true;
//   }
// };

// // Yeah, accepted
// // ref: https://en.wikipedia.org/wiki/Topological_sorting#CITEREFKahn1962
// bool dfs(int n, vector<pair<int, int>>& aa, vector<int>& mark) {
//   if (mark[n] == 2) return true;
//   if (mark[n] == 1) return false;
//   if (mark[n] == 0) {
//     mark[n] = 1;
//     for (auto pair : aa) {
//       if (pair.second == n)
//         if(!dfs(pair.first, aa, mark))
//           return false;
//     }
//     mark[n] = 2;
//   }
//   return true;
// }

// bool canFinish(int numCourses, vector<pair<int, int>>& aa) {
//   vector<int> mark(numCourses, 0);           
//   for (int i=0; i<numCourses; ++i)
//     if (mark[i] == 0) {
//       if (!dfs(i, aa, mark))
//         return false;
//     }
//   return true;
// }

// 
vector<vector<int>> gg;
vector<int> visit;
void makeGraph(int n, vector<pair<int, int>>& pre) {
  gg.resize(n);
  visit.resize(n);
  for (auto pair: pre) {
    gg[pair.second].push_back(pair.first);
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

  for (int i=0; i<numCourses; ++i) {
    if (dfs(i)) return 0;
  }

  return 1;
}

int main(int argc, char** argv) {
    vpii aa = {{0, 1}, {0, 2}, {1, 2}};
    bool r = canFinish(3, aa);
    cout << r << endl;
    return 0;
}
