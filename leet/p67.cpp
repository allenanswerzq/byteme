#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}

string addBinary(string a, string b) {
  string s = "";
  int c=0, i=a.size()-1, j=b.size()-1;
  while (i>=0 || j>=0 || c) {
    c += i>=0 ? a[i--]-'0': 0;
    c += j>=0 ? b[j--]-'0': 0;
    // Note: plus order 
    // so dont need to reverse result string
    s = char(c%2 + '0') + s;
    c /= 2;
  }
  return s;
}


int main(int argc, char** argv) {
  return 0;
}
