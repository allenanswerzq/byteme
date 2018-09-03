#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}

int compareVersion(string version1, string version2) {
  istringstream iss1(version1);
  istringstream iss2(version2);
  while (1) {
    char c;
    int a = -1, b = -1; 
    iss1 >> a >> c;
    iss2 >> b >> c; 
    cout << a << " " << b << endl;
    if (a == -1 && b == -1) break;
    if (a == -1) a = 0;
    if (b == -1) b = 0;
    if (a != b) return a > b ? 1 : -1;
  }
  return 0;
}

// finally, accepted
// :-(
int compareVersion(string version1, string version2) {
  if (version1[0]=='.' || version2[0]=='.') return 0;
  istringstream iss1(version1);
  istringstream iss2(version2);
  char dot;
  int a=INT_MIN, b=INT_MIN;
  iss1 >> a >> dot;
  iss2 >> b >> dot;
  cout << a << " " << b << endl;
  while (a!=INT_MIN && b!=INT_MIN) {
    if (a != b)
      return a>b ? 1:-1;
    else {
      a = b = INT_MIN;
      iss1 >> a >> dot;
      iss2 >> b >> dot;
      if (a==INT_MIN && b==INT_MIN) return 0; // reach the end of input
      if (a==INT_MIN) a = 0;
      if (b==INT_MIN) b = 0;
      cout << a << " " << b << endl;
    }
  }
  return 0; 
}


int main(int argc, char** argv) {
  return 0;
}
