#include "array.h"
using namespace std;

int main() {
  for (int i = 0; i < 100; ++i) {
    int n = rnd.next(1, 30);
    Array a = Array::random(n, 1, 20);
    cout << n << endl;
    cout << a.shuffle() << endl;
    cout << endl;
  }
  return 0;
}
