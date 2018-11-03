#include<bits/stdc++.h>
using namespace std;


// Given a string ss, return all the palindromic permutations (without duplicates) of it. 
// Return an empty list if no palindromic permutation could be form.
// For example:
// Given ss = "aabb", return ["abba", "baab"].
// Given ss = "abc", return [].

class Solution {
public:
  vs generatePalindromes(string ss) {
    vs res;
    unordered_map<char, int> mp;
    string lo = "", mid = "";
    fora (c, ss) mp[c]++;
    fora (it, mp) {
      if (it.second % 2) mid += it.first;
      lo += string(it.second / 2, it.first);
      if (sz(mid) > 1) return {};
    }
    sort(all(lo));
    do {
      res.push_back(lo + mid + string(rall(lo)));
    } while (next_permutation(all(lo)));
    return res;
  }
};

int main(int argc, char** argv) {
  return 0;
}
