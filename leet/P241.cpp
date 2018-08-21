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
  while( n ){
    n = n&(n-1);
    count++;
  }
  return count;
}

char toupper( char a ) {
  return ((a >= 'a' && a <= 'z') ? a-('a'-'A') : a );
}

int main(int argc, char** argv) {
  return 0;
}

// ref: https://discuss.leetcode.com/topic/19894/1-11-lines-python-9-lines-c/2
vector<int> diffWaysToCompute(string input) {
  vector<int> output; 
  for (int i=0; i<input.size(); ++i) {
    char c = input[i];
    //if (c=='+' || c=='-' || c=='*')
    if (ispunct(c)) 
      for (auto a : diffWaysToCompute(input.substr(0, i)))
        for (auto b : diffWaysToCompute(input.substr(i+1)))
          output.push_back(c=='+' ? a+b : c=='-' ? a-b : a*b);
  } 
  return output.size() ? output : vector<int>{stoi(input)}; // Note
}

vector<int> diffWaysToCompute(string input) {

}
