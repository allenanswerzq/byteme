#include<bits/stdc++.h>


using namespace std;

string convertToTitle(int n) {
  string res = "";
  while (n) {
    res = char((n-1)%26 + 'A') + res;
    n = (n-1)/26;
  }
  return res;
}

int main(int argc, char** argv) {
  return 0;
}
