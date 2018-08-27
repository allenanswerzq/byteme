#include<bits/stdc++.h>
using namespace std;


// Given a string s, return all the palindromic permutations (without duplicates) of it. 
// Return an empty list if no palindromic permutation could be form.
// For example:
// Given s = "aabb", return ["abba", "baab"].
// Given s = "abc", return [].

class Solution {
public:
  vs generatePalindromes(string s) {
    vs res;
    unordered_map<char, int> mp;
    string lo = "", mid = "";
    fora (c, s) mp[c]++;
    fora (it, mp) {
      if (it.se % 2) mid += it.fi;
      lo += string(it.se / 2, it.fi);
      if (sz(mid) > 1) return {};
    }
    sort(all(t));
    do {
      res.pb(lo + mid + string(rall(lo)));
    } while (next_permutation(all(lo)));
    return res;
  }
};

int main(int argc, char** argv) {
  return 0;
}