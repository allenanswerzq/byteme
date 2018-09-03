#include<bits/stdc++.h>

using namespace std;

typedef vector<string> vector_t;
typedef set<string> set_t;
typedef queue<string> queue_t;
typedef map<string, int> map_t;

// BFS
int openLock(vector<string>& deadends, string target) {
  set_t dead;
  for (auto d : deadends) dead.insert(d);
  queue_t q;
  map_t mp;
  q.push("0000");
  mp["0000"] = 0;
  int cnt = 0;
  bool ok = false;
  while (!q.empty()) {
  cnt++;
  int size = q.size();
  for (int k=0; k<size; ++k) {
  string parent = q.front(); q.pop();
  if (dead.count(parent)) continue;
  for (int i=0; i<4; ++i) {  // for each wheel
  for (int j=-1; j<=1; j+=2) { // for each direction
    string child  = parent;
    child[i] += j;
    if (child[i] > '9') child[i] -= 10;
    if (child[i] < '0') child[i] += 10;
    if (mp.count(child)) continue;  // if this child already visited
    if (child == target) { 
    ok = true;
    return cnt;
    }
    q.push(child);
    mp[child] = mp[parent] + 1;
  }
  }  
  }
  }
  return ok==false ? -1:cnt;
}

// BFS
int openLock(vector<string>& deadends, string target) {
  set_t dead;
  for (auto d : deadends) dead.insert(d);
  queue_t q;
  map_t mp;
  q.push("0000");
  mp["0000"] = 0;  // record every distance from child node to source node

  while (!q.empty()) {
  string parent = q.front(); q.pop();
  if (dead.count(parent)) continue;
  for (int i=0; i<4; ++i) {  // for each wheel
  for (int j=-1; j<=1; j+=2) { // for each direction
  string child = parent;
  child[i] += j;
  if (child[i] > '9') child[i] -= 10;
  if (child[i] < '0') child[i] += 10;
  if (mp.count(child)) continue;
  mp[child] = mp[parent] + 1;   // distance from child to source
  q.push(child);
  }
  }  
  }
  return mp.count(target) ? mp[target] : -1;
}
