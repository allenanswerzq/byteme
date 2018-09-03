#include<bits/stdc++.h>
using namespace std;



template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args> 
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ','); 
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...); 
} 

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
  deque<int> dq;
  fora (str, tokens) {
  if (sz(dq) && str == "+") {
  int a = dq.back(); dq.ppb();
  int b = dq.back(); dq.ppb();
  trace(a, b);
  dq.pb(b + a);
  } else if (sz(dq) && str == "-") {
  int a = dq.back(); dq.ppb();
  int b = dq.back(); dq.ppb();
  trace(a, b);
  dq.pb(b - a);
  } else if (sz(dq) && str == "*") {
  int a = dq.back(); dq.ppb();
  int b = dq.back(); dq.ppb();
  trace(a, b);
  dq.pb(b * a);
  } else if (sz(dq) && str == "/") {
  int a = dq.back(); dq.ppb();
  int b = dq.back(); dq.ppb();
  trace(a, b);
  dq.pb(b / a);
  } else {
  dq.pb(stoi(str));
  }
  }      
  return dq.back();
  }
};


int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("p150-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();


  int t; cin >> t;
  fori (i, 1, t + 1) {
  
  }  

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
