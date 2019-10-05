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
  puts(T);
  int n = 1e5;
  int g = 1e5;
  int m = 1e9;
  puts(n, g, m);
  for (int i = 0; i < g; ++i) {
    int x = rnd.next(1, n);
    int y = rnd.next(0, 1);
    char op = (y == 0 ? 'C' : 'A');
    puts(x, op);
  }
}

int main() {
  for (int t = 0; t < T; ++t) {
    gen();
    cout << endl;
  }
  return 0;
}
