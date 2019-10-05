#include "array.h"
using namespace std;

int main() {
  for (int i = 0; i < 10; ++i) {
    int n = rnd.next(200000);
    Array a = Array::random(n, 1, 2);
    cout << n << endl;
    cout << a << endl;
    cout << endl;
  }
  return 0;
}
