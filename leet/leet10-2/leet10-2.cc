/* created   : 2020-10-05 16:59:34
 * accepted  : 2020-10-05 17:21:22
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

// TODO(): complete this
/*    |-->out
   c-->
      |-->out1
*/
struct State {
  int c;
  int out;
  int out1;
  friend ostream& operator<<(ostream& os, const State& s) {
    return os << s.c << " " << s.out << " " << s.out1 << "\n";
  }
};

enum { Start = -1, Match = 256, Split = 257 };

class Solution {
public:
  bool isMatch(string S, string P) {
    vector<State> nfa;
    nfa.push_back(State{Start, nfa.size() + 1, -1});
    for (int i = 0; i < P.size(); i++) {
      if (P[i] == '*') {
        int j = i;
        while (j < P.size() && P[j] == '*') j++;
        i = j - 1;
        nfa.push_back(State{Split, nfa.size() + 1, nfa.size() - 1});
      }
      else {
        nfa.push_back(State{P[i], nfa.size() + 1, -1});
      }
    }
    nfa.push_back(State{Match, -1, -1});
    trace(nfa);
    deque<int> qu;
    qu.push_back(0);
    while (qu.size()) {
      int u = qu.front(); qu.pop_front();
    }
    return false;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

int test(const string& s, const string& p) {
  Solution sol;
  return sol.isMatch(s, p);
}

void solve() {
  EXPECT(test("aa", "a"), 0);
  EXPECT(test("aa", "a*"), 1);
  EXPECT(test("", ".*"), 1);
  EXPECT(test("", ".*************"), 1);
  EXPECT(test("ab", ""), 0);
  EXPECT(test("ab", ".*"), 1);
  EXPECT(test("aab", "c*a*b"), 1);
  EXPECT(test("mississippi", "mis*is*p*."), 0);
  EXPECT(test("a", "ab*"), 1);
  EXPECT(test("a", "ab*a"), 0);
  EXPECT(test("a", ".*.."), 0);
  EXPECT(test("", "c*c*"), 1);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
