#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    printf("[ ");
    for (auto x:v)
        printf("%d ", x); 
    printf("]\n");
}

// Accepted
// but the process has a lot pain. :(
vector<vector<int>> next;
vector<int> mark;
vector<int> res;

void makeGraph(int n, vector<pair<int, int>>& pre) {
  next.resize(n);
  mark.resize(n);
  for (auto pair: pre) {
    // after finished pair.second we start to do pair.first
    next[pair.second].push_back(pair.first);
  }

}

bool dfs(int i, vector<int>& res) {
  if (mark[i] == 2) return false; // already visited
  if (mark[i] == 1) return true;  // exists cycle

  mark[i] = 1;
  for (auto nxt : next[i]) 
    if (dfs(nxt, res) == true) return false;

  res.push_back(i);
  mark[i] = 2;
 return false;
}

vector<int> findOrder(int numCourses, vector<pair<int, int>>& pre) {
  makeGraph(numCourses, pre); 
  
  for (int i=0; i<numCourses; ++i)
    if (dfs(i, res) == true) return {}; // if there is a cycle return empty vector
  
  reverse(res.begin(), res.end());
  return res;
}

int main(int argc, char** argv) {
    return 0;
}
