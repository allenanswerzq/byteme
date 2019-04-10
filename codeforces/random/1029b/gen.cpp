#include "array.h"
using namespace std;


int main() {
  int T = 10;
  for (int t = 0; t < T; ++t) {
    int n = rnd.next(1, (int)10);
    Array a = Array::random(n, 1, 1e2);
    sort(a.begin(), a.end());
    cout << n << endl;
    cout << a << endl << endl;
  }
  return 0;
}

