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

class MyStack {
public:
    queue<int> q;        
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
      q.push(x);
      for (int i=1; i<q.size(); ++i) {
        q.push(q.front());
        q.pop();
      }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
      int top = q.front();
      q.pop();    
      return top;
    }
    
    /** Get the top element. */
    int top() {
       return q.front(); 
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
       return q.empty(); 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
