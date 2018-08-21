#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  printf("[ ");
  for (auto x:v)
      printf("%d ", x);
  printf("]\n");
}

void printMatrix(vector<vector<int>>& v) {
  printf("{\n");
  for (auto x:v)
    printVector(x);
  printf("}\n");
}

bool isPowerOfTwo(int x) {
  //return (x && !(x & (x-1)));
  return x* !(x&(x-1)) > 0;
}

int countOne (int n){
  int count=0;
  while( n ){
    n = n&(n-1);
    count++;
  }
  return count;
}

char toupper( char a ) {
  return ((a >= 'a' && a <= 'z') ? a-('a'-'A') : a );
}

//Given a string, determine if a permutation of the string could form a palindrome.
//For example,
//"code" -> False, "aab" -> True, "carerac" -> True.
bool canPermutePalindrome(string s) {
  if (s == "") return true;
  map<char, int> mp;
  for (auto c : s) 
    mp[c]++;
  int cnt=0;
  for (auto m : mp) {
    if (m.second % 2) cnt++;
  //if (m.second & 1 ) cnt++;
    if (cnt > 1) return false;
  }
  return true;
}

//python
//def canPermutePalindrome(self, s):
//  return sum(v%2 for v in collections.Counter(s).values()) < 2

int main(int argc, char** argv) {
  cout << canPermutePalindrome("code") << "\n";
  cout << canPermutePalindrome("aab") << "\n";
  cout << canPermutePalindrome("carerac") << "\n";
  return 0;
}
