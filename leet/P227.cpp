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

// 
int calculate(string s) {
	istringstream in('+' + s + '+');
	long long total = 0, term=0;
	char op;
	while (in >> op) {
		if (op == '+' || op == '-') {
			total += term;
			in >> term;
			term *= op == '-' ? -1:1;
		}	else {
			int tmp;
			in >> tmp;
			if (op == '*')
				term *= tmp;
			if (op == '/')
				term /= tmp;	
		}
	}
	return total;
}

int main(int argc, char** argv) {
  return 0;
}
