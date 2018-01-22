#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

typedef long long int64;
//NOTE:
//1). overflow
//2). number starts with 0
//3). multipy problem
void dfs(vector<string>& res, const string num, int target, string path, int idx, 
  int64 sum, int last, char op) {
  if (idx==num.size() && sum==target) {
    res.push_back(path);
  } else {
    for (int i=idx+1; i<=num.size(); ++i) {
      string t = num.substr(idx, i-idx);
      if (t[0]=='0' && t.size()>1) continue; 
      int64 now = stoll(t);
      dfs(res, num, target, path+'+'+t, i, sum+now, now, '+');
      dfs(res, num, target, path+'-'+t, i, sum-now, now, '-');
      //NOTE: kind of trick to handle multipy
      dfs(res, num, target, path+'*'+t, i, op=='+' ? sum-last+last*now : op=='-' ? sum+last-last*now : last*now,
        last*now, op);
    }
  }
}

vector<string> addOperators(string num, int target) {
  vector<string> ret;
  if (num.empty()) return ret;
  for (int i=1; i<=num.size(); ++i) {
    string s = num.substr(0, i); 
    if(s[0]=='0' && s.size()>1) continue;
    int64 cur = stoll(s);
    dfs(ret, num, target, s, i, cur, cur, '#');
  }
  return ret;
}

int main() {
  //vector<string> ret = addOperators("3456237490", 9191);
  vector<string> ret = addOperators("2147483648", -2147483648);
  cout << sizeof(long) << endl;
  cout << sizeof(int64) << endl;
  for (auto s : ret)
    cout << s << "\n";
  return 0;
}