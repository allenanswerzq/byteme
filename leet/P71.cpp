#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
  cout << x << " ";
  cout <<"] " << endl;
}
// vary good stack problem
// i cant think how to solve this 
string simplifyPath(string path) {
  vector<string> stk;
  stringstream ss(path);
  string x = "";
  while(getline(ss, x, '/')) {
  if (x == "..") {
    if (!stk.empty())
    stk.pop_back();
  }
  else if(x!="" && x!=".")
    stk.push_back(x);
  }
  string res;
  // NOTE: stack cant do this
  // but vector can
  for (auto x: stk) {
  res = res + '/' + x;
  }
  return stk.empty() ? "/":res;
}

int main(int argc, char** argv) {
  return 0;
}
