/* created   : 2019-09-28 20:24:45
 * accepted  : 2019-09-28 20:33:48
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

// A string prase function, split string using `delim`.
vector<string> parse(string& s, string delim = ",") {
  int cur = 0;
  int last = 0;
  int n = s.size();
  vector<string> ret;
  while (cur < n) {
    cur = s.find(delim, last);
    if (cur == -1) {
      cur = n;
    }
    string x = s.substr(last, cur - last);
    ret.push_back(x);
    last = cur + 1;
  }
  return ret;
}

void test() {
  string s = "1,28,300.1,San Francisco";
  trace(parse(s));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  test();
  return 0;
}
