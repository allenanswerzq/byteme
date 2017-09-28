#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <sstream>  // std:istringstream
#include <queue>
#include <deque>
#include <iterator>

using namespace std;

void printVector(vector<int>& v) {
    printf("[ ");
    for (auto x:v)
        printf("%d ", x); 
    printf("]\n");
}

// Yeah, accepted
// ref: https://en.wikipedia.org/wiki/Topological_sorting#CITEREFKahn1962
bool dfs(int n, vector<pair<int, int>>& prerequisites, vector<int>& mark) {
  if (mark[n] == 2) return true;
  if (mark[n] == 1) return false;
  if (mark[n] == 0) {
    mark[n] = 1;
    for (auto pair : prerequisites) {
      if (pair.second == n)
        if(!dfs(pair.first, prerequisites, mark))
          return false;
    }
    mark[n] = 2;
  }
  return true;
}

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
  vector<int> mark(numCourses, 0);           
  for (int i=0; i<numCourses; ++i)
    if (mark[i] == 0) {
      if (!dfs(i, prerequisites, mark))
        return false;
    }
  return true;
}

// 
vector<vector<int>> next;
vector<int> mark;
void makeGraph(int n, vector<pair<int, int>>& pre) {
  next.resize(n);
  mark.resize(n);
  for (auto pair: pre) {
    next[pair.second].push_back(pair.first);
  }
}

bool dfs(int i) {
  if (mark[i] == 2) return false;
  if (mark[i] == 1) return true;
  mark[i] = 1;
  for (auto nxt : next[i]) 
    if (dfs(nxt)) return false;
  mark[i] = 2;
 return false;
}

bool canFinish(int numCourses, vector<pair<int, int>>& pre) {
  makeGraph(numCourses, pre); 

  for (int i=0; i<numCourses; ++i)
    if (dfs(i)) return false;

  return true;
}

int main(int argc, char** argv) {
    return 0;
}
