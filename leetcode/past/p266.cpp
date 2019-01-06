#include <bits/stdc++.h>
using namespace std;

//Given a string, determine if a permutation of the string could form a palindrome.
//For example,
//"code" -> False, "aab" -> True, "carerac" -> True.

class Solution {
public:
  bool canPermutePalindrome(string s) {
    if (s == "") return true;
    map<char, int> mp;
    for (auto c : s) mp[c]++;

    int cnt = 0;
    for (auto m : mp) {
      if (m.second % 2) cnt++;
      if (cnt > 1) return false;
    }
    return true;
  }
};

void test(string aa) {
  Solution go;
  int r = go.canPermutePalindrome(aa);
  output(1, r);
}

int main() {
  test("code");
  test("aab");
  test("carerac");
  return 0;
}
