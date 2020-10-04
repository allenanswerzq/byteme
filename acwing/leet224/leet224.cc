/* created   : 2020-10-04 11:18:16
 * accepted  : 2020-10-04 12:04:40
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  int get_precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
  }

  int impl(const string& S) {
    vector<int> stk;
    stringstream ss(S);
    string t;
    while (ss >> t) {
      if (isdigit(t[0])) {
        stk.push_back(stoi(t));
      }
      else {
        assert(t.size() == 1);
        char op = t[0];
        assert(stk.size() >= 2);
        int b = stk.back(); stk.pop_back();
        int a = stk.back(); stk.pop_back();
        if (op == '+') {
          stk.push_back(a + b);
        }
        else if (op == '-') {
          stk.push_back(a - b);
        }
        else if (op == '/') {
          stk.push_back(a / b);
        }
        else if (op == '*') {
          stk.push_back(a * b);
        }
        else if (op == '^') {
          stk.push_back(a ^ b);
        }
        else {
          assert(false);
        }
      }
    }
    assert(stk.size() == 1);
    return stk.back();
  }

  // infix:    "a+b*(c^d-e)^(f+g*h)-i"
  // postfix:  "abcd^e-fgh*+^*+i-"
  int calculate(string S) {
    vector<char> stk;
    string postfix;
    int n = S.size();
    for (int i = 0; i < n; i++) {
      // trace(i, S[i]);
      if (S[i] == ' ') {
      }
      else if (isdigit(S[i])) {
        int j = i;
        while (j < n && isdigit(S[j])) j++;
        postfix.append(S.substr(i, j - i));
        postfix.append(" ");
        i = j - 1;
        // trace(stk, postfix);
      }
      else if (S[i] == '(') {
        stk.push_back(S[i]);
      }
      else if (S[i] == ')') {
        // trace(stk, postfix);
        while (stk.size() && stk.back() != '(') {
          postfix.append(string(1, stk.back()));
          postfix.append(" ");
          stk.pop_back();
        }
        // trace(stk);
        assert(stk.size() && stk.back() == '(');
        stk.pop_back();
      }
      else {
        int order = get_precedence(S[i]);
        // NOTE: pop up all operators that have a higher precedence.
        while (stk.size() && get_precedence(stk.back()) >= order) {
          postfix.append(string(1, stk.back()));
          postfix.append(" ");
          stk.pop_back();
        }
        stk.push_back(S[i]);
        // trace("aaa", stk, postfix);
      }
    }
    while (stk.size()) {
      postfix.append(string(1, stk.back()));
      postfix.append(" ");
      stk.pop_back();
    }
    trace(postfix);
    return impl(postfix);
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

int test(string S) {
  Solution sol;
  return sol.calculate(S);
}

void solve() {
  EXPECT(dbg(test("1 + 2")), 3);
  test("3+4*(2^8-5)^(7+4*3)-2");
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
