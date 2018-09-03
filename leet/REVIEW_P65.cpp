#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}

bool isNumber(string s) {
  int n = s.size();
  int i = 0;
  while(s[i] == ' ') {s.erase(i); i++;}
  i = n-1;
  while(s[i] == ' ') {s.erase(i); i--;}
  cout << "S: " << s << endl; 
  for (i=0; i<n; ++i) {
    if (s[i]<'0' || s[i]>'9' || s[i]!='.' || s[i]!='e') 
      return false;
    if (s[i] == '.') {
      if (i == 0) return false;
      if (isNumber(s.substr(i+1)) return true;
    }
    if (s[i] == 'e') {
      if (i == 0) return false;
      if (isNumber(s.substr(i+1)) return true;
    }
  }
  return true;
}

int main(int argc, char** argv) {
  return 0;
}
