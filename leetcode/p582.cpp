#include<bits/stdc++.h>using namespace std;

vector<int> helper(int kill, unordered_map<int, vector<int>> m) {
  vector<int> ret;
  if (m.find(kill) != m.end() ) {
    vector<int> v;
    v = m[kill];
    for (auto k : v) {
      vector<int> r = helper(k, m);
      for (auto val : r)
        ret.push_back(val);
    }
    for (auto val: v) {
      ret.push_back(val);
    }
    return ret;
  } else {
    return ret;
  }
}

vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
  vector<int> ret;
  if (kill == 0) {pid.insert(pid.begin(), 0); return pid;}
  unordered_map <int, vector<int>> m;
  for (int i=0; i<ppid.size(); ++i) {
    m[ppid[i]].push_back(pid[i]);
  }

  ret.push_back(kill);
  int queue[pid.size() + 1];
  int k = 0;
  queue[k++] = kill;
  while (k != 0) {
    int x = queue[--k];
    for (int v : m[x]) {
      queue[k++] = v;
      ret.push_back(v);
    }
  }
  return ret;
}

int main() {
  return 0;
}
