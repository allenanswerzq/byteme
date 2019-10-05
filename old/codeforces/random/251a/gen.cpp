#include "array.h"
using namespace std;

int main() {
  for (int i = 0; i < 10; ++i) {
    int mx = (int) 100000;
    int d = rnd.next(1, (int) 1e9);
    cout << mx << " " << d << endl;
    Array a = Array::randomUnique(mx, 1, 1e9);
    sort(a.begin(), a.end());
    cout << a << endl << endl;
  }
  return 0;
}
