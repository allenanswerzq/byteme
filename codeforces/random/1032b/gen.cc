#include "array.h"
#include "rnds.h"
using namespace std;

template<class T> void output(T t) { cout << t << "\n"; }
template<class T, class U, class... G>
void output(T t, U u, G... g) { cout << t << " "; output(u, g...); }

// The number of test cases.
const int T = 10;

void gen() {
  // Write your own test generating code here.
  int n = 100;
  string s = rnds.random(n);
  output(s);
}

int main() {
  for (int t = 0; t < T; ++t) {
    gen();
    cout << endl;
  }
  return 0;
}
