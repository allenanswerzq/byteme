#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}

void reverseWords(string &s) {
  istringstream iss(s);
  bool mark = true;
  string word;
  s = "";
  while (iss >> word) {
    s = word + (mark ? "" : " ") + s;
    mark = false;
  }    
}

int main(int argc, char** argv) {
  string s = "the sky is blue";
  reverseWords(s);
  cout << s << endl;
  return 0;
}
