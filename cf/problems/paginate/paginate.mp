/* created   : 2020-01-13 19:42:20
 * accepted  : 2020-01-13 20:03:26
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

vector<string> f(const vector<string> &strings) {
    vector<unordered_set<int>> m;
    vector<vector<int>> v;
    for (int i = 1, b = 0; i < strings.size(); ++i) {
        int host_id = stoi(strings[i].substr(0, strings[i].find(",")));
        int j = b;
        for (; j < v.size(); ++j) {
            if (v[j].size() < 12 && !m[j].count(host_id)) {
                v[j].push_back(i);
                m[j].insert(host_id);
                if (v[j].size() == 12) {
                    b = j + 1;
                }
                break;
            }
        }
        if (j == v.size()) {
            v.push_back({i});
            m.push_back({host_id});
        }
    }
    vector<string> res{"host_id,listing_id,score,city"};
    for (const auto &indices : v) {
        for (int idx : indices) {
            res.push_back(strings[idx]);
        }
        res.push_back("\n");
    }
    return res;
}

int main() {
  vector<string> a;
  string str;
  while (getline(cin, str)) {
    trace(str);
    a.push_back(str);
  }
  trace(a);
  for (const auto &s : f(a)) {
      cout << s << endl;
  }
  return 0;
}
