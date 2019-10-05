#include "array.h"
#include "rnds.h"
using namespace std;

template<class T> void puts(T t) { cout << t << "\n"; }
template<class T, class U, class... G>
void puts(T t, U u, G... g) { cout << t << " "; puts(u, g...); }

template<class T> void trace(T t) { cerr << t << "\n"; }
template<class T, class U, class... G>
void trace(T t, U u, G... g) { cerr << t << " "; puts(u, g...); }

// The number of test cases.
const int T = 1;

void gen() {
  // Write your own test generating code here.
  int n = rnd.next(1, 1e5);
  int m = rnd.next(1, 1e5);
  puts(1);
  puts(n, m);
  for (int i = 0; i < m; i++) {
    int x = rnd.next(1, 1e4);
    int y = rnd.next(1, 1e4);
    puts(x, y);
  }
  for (int i = 0; i < n; i++) {
    int x = rnd.next(1, 1e8);
    int y = rnd.next(1, 1e8);
    puts(x, y);
  }
}

int main() {
  for (int t = 0; t < T; ++t) {
    gen();
    cout << endl;
  }
  return 0;
}
