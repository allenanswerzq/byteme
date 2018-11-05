#include <bits/stdc++.h>
using namespace std;

vector<int> exclusiveTime(int n, vector<string>& logs) {
  vector<int> res(n), stk(logs.size()+2);
  int k=0, ctime, ltime;
  int id;
  char str[10];
  for (auto log : logs) {
    // Note: use sscanf or stringstream to parse input
    sscanf(log.c_str(), "%d:%[a-z]:%d", &id, str, &ctime);
    if (str[0] == 's') { // if start
      if(k>0) res[stk[k-1]] += ctime - ltime;
      stk[k++] = id;
    } else {
      // Note: ++citme
      res[stk[k-1]] += ++ctime - ltime;
      k--;
    }
    ltime = ctime;
  }
  return res;
}

int main() {
  return 0;
}
