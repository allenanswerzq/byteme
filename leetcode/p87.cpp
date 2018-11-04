#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool recu(string s1, string s2) { 
    int a, b;
    a = sz(s1), b = sz(s2);
    if (s1 == s2) return true;
    if (a != b) return false;

    int cnt[26] = {};
    fori (i, 0, a) {
      cnt[s1[i] - 'a']++;
      cnt[s2[i] - 'a']--;
    }

    fori (i, 0, 26)
      if (cnt[i] != 0) 
        return false;

    int n = a;
    fori (i, 1, n) {
      if (recu(s1.substr(0, i), s2.substr(0, i)) && 
        recu(s1.substr(i), s2.substr(i)))
        return true;

      if(recu(s1.substr(0, i), s2.substr(n-i)) &&
       recu(s1.substr(i), s2.substr(0, n-i)))
        return true;
    } 
    return false;
  }
};

class Solution {
public:
  bool isScramble(string s1, string s2) {
    return recu(s1, s2);      
  }
};

void test(string s1, string s2) {
  Solution go;
  cout << go.isScramble(s1, s2) << "\n";
}

int main() {
 
  test("abc", "bca");
  test("great", "rgeat");
  test("abcde", "caebd");
  
  return 0;
}
