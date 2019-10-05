#include "array.h"
#include "rnds.h"
using namespace std;

template<class T> void output(T t) { cout << t << "\n"; }
template<class T, class U, class... G>
void output(T t, U u, G... g) { cout << t << " "; output(u, g...); }

// The number of test cases.
const int T = 100;

void gen() {
  // Write your own test generating code here.
  const int maxn = 10;
  const int maxm = 10;
  int n = rnd.next(1, maxn);
  int m = rnd.next(0, n);
  output(n, m);
  for (int i = 0; i < n; ++i) {
    // const int maxv = 1e9;
    const int maxv = 10;
    int k = rnd.next(1, maxv);
    int l = rnd.next(1, maxv);
    output(k, l);
  }
}

int main() {
  for (int t = 0; t < T; ++t) {
    gen();
    cout << endl;
  }
  return 0;
}
