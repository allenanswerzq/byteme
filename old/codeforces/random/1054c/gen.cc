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
const int T = 10;

void gen() {
  // Write your own test generating code here.
  auto v = Array::random(1000, 0, 1000);
  int n = v.size();
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < i; j++) {
      if (v[j] > v[i]) {
        cnt++;
      }
    }
    a[i] = cnt;
  }
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = i + 1; j < n; j++) {
      if (v[j] > v[i]) {
        cnt++;
      }
    }
    b[i] = cnt;
  }
  trace(v);
  puts(n);
  puts(a);
  puts(b);
}

int main() {
  for (int t = 0; t < T; ++t) {
    gen();
    cout << endl;
  }
  return 0;
}
