#include<bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

bool isAnagram(string s, string t) {
  if (sz(s) != sz(t)) return false;     
  unordered_map<char, int> mp;
  for (int i=0; i<s.size(); ++i) {
  mp[s[i]]++;
  mp[t[i]]--;
  }
  for (auto it : mp)
  if (it.second > 0)
  return false;
  return true;
}

int main(int argc, char** argv) {
  return 0;
}
