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

class MyQueue {
public:
    stack<int> in;
    stack<int> out;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
      in.push(x); 
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
      int x = peek();     // make true out is not empty so it contains front number
      out.pop();  // then pop front number
      return x;
    }
    
    /** Get the front element. */
    int peek() {
      if (out.empty()) { // only push into out when out is empty otherwise it will break order of queue
        while(!in.empty()) {
          out.push(in.top());
          in.pop();
        }    
      } 
      return out.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
      return in.empty() && out.empty();    
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
