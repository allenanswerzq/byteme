#include "rnds.h"
using namespace std;

int main() {
  for (int i = 0; i < 20; ++i) {
    string a = rnds.random(10, "1-9");
    cout << a.size() << endl;
    string b = rnds.random(9, "1-9");
    cout << a << endl;
    for (int i = 0; i < 9; ++i) {
      cout << b[i] << (i == 8 ? "\n" : " ");
    }
    cout << endl;
  }
}
