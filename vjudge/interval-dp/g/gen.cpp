#include "rnds.h"
using namespace std;

int main() {
  for (int i = 0; i < 100; ++i) {
    string a = rnds.random(100, "a-z");
    string b = rnds.random(100, "a-z");
    cout << a << endl;
    cout << b << endl;
  }
  return 0;
}
