#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
  cout << x << " ";
  cout <<"] " << endl;
}

// Accepted
int calPoints(vector<string>& ops) {
  vector<int> stk(ops.size(), 0);
  int sum=0, k=0; 
  for(auto m : ops) {
  	if (m == "C") {sum -= stk[k-1]; k--;}
  	else if(m == "D") {
  		int t = stk[k-1]*2;
  		stk[k++] = t;
  		sum += t;
  	} 
  	else if(m == "+") {
  		int t = stk[k-1]+stk[k-2];
  		stk[k++] = t;
  		sum += t;
  	}
  	else {
  		sum += stoi(m);
  		stk[k++] = stoi(m);
  	}
  }  
  return sum;
}

int main(int argc, char** argv) {
  return 0;
}
