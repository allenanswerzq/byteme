#include "array.h"
#include "rnds.h"
using namespace std;

template<class T> void puts(T t) { cout << t << "\n"; }
template<class T, class U, class... G>
void puts(T t, U u, G... g) { cout << t << " "; puts(u, g...); }

// The number of test cases.
const int T = 1;

void gen() {
  // Write your own test generating code here.
  int n = 30;
  int d = 10;
  puts(n, d);
  for (int i = 0; i < n; ++i) {
    auto x = Array::random(d, 1, 100);
    puts(x);
  }
}

int main() {
  for (int t = 0; t < T; ++t) {
    gen();
    cout << endl;
  }
  return 0;
}
