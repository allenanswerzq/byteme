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
  int n = 1e5;
  int q = 1e5;
  puts(T);
  puts(n, q);
  auto a = Array::random(n, 0, 1024);
  puts(a);
  for (int i = 0; i < q; i++) {
    int x = rnd.next(1, n);
    int y = rnd.next(0, 1024);
    puts(x - 1, y);
  }
}

int main() {
  for (int t = 0; t < T; ++t) {
    gen();
    cout << endl;
  }
  return 0;
}
