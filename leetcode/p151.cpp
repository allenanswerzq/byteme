#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  void reverseWords(string &ss) {
    istringstream iss(ss);
    bool mark = true;
    string word;
    ss = "";
    while (iss >> word) {
      ss = word + (mark ? "" : " ") + ss;
      mark = false;
    }    
  }
};

int main() {
  return 0;
}
