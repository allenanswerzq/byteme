#include "array.h"
using namespace std;

int main() {
  int mx = (int) 1e5;
  cout << mx << " " << mx << " " << 13 << " " << 420000 << endl;
  Array a = Array::random(100000, 1, 1e9);
  Array b = Array::random(100000, 1, 1e9);
  cout << a << endl;
  cout << b << endl;
  return 0;
}
