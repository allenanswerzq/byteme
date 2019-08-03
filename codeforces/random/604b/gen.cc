#include "array.h"
#include "rnds.h"
using namespace std;

template<class T> void puts(T t) { cout << t << "\n"; }
template<class T, class U, class... G>
void puts(T t, U u, G... g) { cout << t << " "; puts(u, g...); }

// The number of test cases.
const int T = 100;

void gen() {
  // Write your own test generating code here.
  int n = rnd.next(1, 10);
  int k = rnd.next(1, 5);
  while (2 * k < n) {
    k = rnd.next(1, 5);
  }
  auto a = Array::random(n, 1, 100);
  sort(a.begin(), a.end());
  puts(n, k);
  puts(a);
}

int main() {
  for (int t = 0; t < T; ++t) {
    gen();
    cout << endl;
  }
  return 0;
}
