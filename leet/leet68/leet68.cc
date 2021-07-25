/* created   : 2020-09-16 10:26:20
 * accepted  : 2020-09-16 22:14:21
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  vector<string> fullJustify(vector<string>& A, int width) {
    int n = A.size();
    vector<int> ps(n + 1);
    for (int i = 0; i < n; i++) {
      ps[i + 1] = ps[i] + (int) A[i].size();
    }
    auto get = [&](int x, int y) {
      return ps[y + 1] - ps[x];
    };
    auto go = [&](int lo, int hi) {
      string ret;
      if (lo == hi || hi == n - 1) {
        for (int k = lo; k <= hi; k++) {
          ret.append(A[k]);
          if (k < hi) ret.append(" ");
        }
        ret.append(string(max(width - (int) ret.size(), 0), ' '));
      }
      else {
        int rest = width - get(lo, hi);
        int sp = rest / (hi - lo);
        int ss = rest % (hi - lo);
        // trace(rest, sp, ss);
        for (int k = lo; k <= hi; k++) {
          ret.append(A[k]);
          if (k < hi) {
            ret.append(string(sp, ' '));
            if (ss) {
              ret.append(string(1, ' '));
              ss--;
            }
          }
        }
      }
      // trace(ret);
      assert(ret.size() == width);
      return ret;
    };
    vector<string> ans;
    int start = 0;
    while (start < n) {
      int lo = start;
      int hi = n;
      // trace(lo, hi, start, A);
      while (lo + 1 < hi) {
        int md = lo + (hi - lo) / 2;
        // trace(lo, hi, md, get(lo, md) + (md - lo));
        if (get(start, md) + (md - start) <= width) {
          lo = md;
        }
        else {
          hi = md;
        }
      }
      // [start ... lo]
      // trace(start, lo, hi);
      assert(get(start, lo) + lo - start <= width);
      ans.push_back(go(start, lo));
      start = lo + 1;
    }
    // trace(ans);
    return ans;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

vector<string> test(vector<string> A, int w) {
  Solution sol;
  return sol.fullJustify(A, w);
}

void solve() {
  EXPECT(
      test({"This", "is", "an", "example", "of", "text", "justification."}, 16),
      vector<string>(
          {"This    is    an", "example  of text", "justification.  "}));

  EXPECT(test({"What", "must", "be", "acknowledgment", "shall", "be"}, 16),
         vector<string>(
             {"What   must   be", "acknowledgment  ", "shall be        "}));

  EXPECT(test({"Science", "is", "what", "we", "understand", "well", "enough",
               "to", "explain", "to", "a", "computer.", "Art", "is",
               "everything", "else", "we", "do"},
              20),

         vector<string>({"Science  is  what we", "understand      well",
                         "enough to explain to", "a  computer.  Art is",
                         "everything  else  we", "do                  "}));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
