#include "array.h"
using namespace std;

int main() {
  int T = 10;
  cout << T << endl;
  for (int t = 0; t < T; ++t) {
    int n = 5;
    Array a = Array::random(n, 0, 100);
    cout << n << endl;
    cout << a << endl;
  }
  return 0;
}
