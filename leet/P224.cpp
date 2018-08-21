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
    
int main(int argc, char** argv) {
  return 0;
}
// good stack problem
int calculate(string s) {
	stack<int> stk;
	int sign = 1, result=0;
	for (int i=0; i<s.size(); ++i) {
		if (s[i] >= '0') {
			int num = 0;
			while (i<s.size() && s[i]>='0')
				num = num*10 + s[i++]-'0';
			--i;
			result += sign*num;
		} else if (s[i] == '+') sign = 1;
		else if (s[i] == '-') sign = -1; 
		else if (s[i]=='(') {
			stk.push(result);
			stk.push(sign);
			result = 0;
			sign = 1;
		} else if (s[i]==')') {
			int s = stk.top(); stk.pop();
			int t = stk.top(); stk.pop();
			result = t + s*result;
		}
	}
	return result;
}
