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

int steps(int source, int step, int dest) {
    if (abs(source) > (dest)) return INT_MAX;
    if (source == dest) return step;
    int pos = steps(source + step + 1, step + 1, dest);
    int neg = steps(source - step - 1, step + 1, dest);
    return min(pos, neg);
}


int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  int inp; cin >> inp;
  cout << steps(0, 0, inp) << endl;

  return 0;
}
