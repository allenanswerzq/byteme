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
  return (x && !(x & (x-1)));
  }

int countOne (int n){
  while( n ){
  n = n&(n-1);
  count++;
  }
  return count;
}

char toupper( char a ) {
  return ((a >= 'a' && a <= 'z') ? a-('a'-'A') : a );
}

// NOTE: cmp must be static inside a class
static bool cmp(string& s1, string& s2) {
  if (s1.size() == s2.size()) return s1 < s2; // if size equals, return lexicographically smaller
  return s1.size() > s2.size();               // otherwise return longer
}

string longestWord(vector<string>& words) {
  set<string> st;
  for (auto w:words) st.insert(w);
  sort(words.begin(), words.end(), cmp);
  for (auto wd : words) {
  int sz = wd.size();
  string cur = "";
  int flag = 1;
  for (int i=0; i<sz; ++i) {
    cur.push_back(wd[i]);
    if (st.count(cur) == 0) {
    flag = 0; break;
    }
  }
  if (flag) return wd;
  }
  return "";
}

int main(int argc, char** argv) {
  return 0;
}
