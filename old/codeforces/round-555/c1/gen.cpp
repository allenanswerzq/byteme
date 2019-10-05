#include "array.h"
using namespace std;

int main() {
  for (int i = 0; i < 10; ++i) {
    int n = rnd.next(1, 10);
    Array a = Array::id(n, 1);
    cout << n << endl;
    cout << a.shuffle() << endl;
    cout << endl;
  }
  return 0;
}
