#include "rnds.h"
using namespace std;

int main() {
  int t = 100;
  cout << t << endl;
  for (int i = 0; i < t; ++i) {
    int n = rnd.next(100);
    string s = rnds.random(n, "ab");
    cout << s << endl;
  }
  cout << endl;
  return 0;
}
