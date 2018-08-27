#include<bits/stdc++.h>
using namespace std;

// (100a+10b+c)%9 = (a+99a+b+9b+c)%9 = (a+b+c)%9
int addDigits(int num) {
  if (num == 0) return 0;        
  return num % 9 == 0 ? 9 : num % 9;
}

int main(int argc, char** argv) {
  return 0;
}