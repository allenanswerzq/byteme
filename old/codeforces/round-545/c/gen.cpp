#include "array.h"
using namespace std;

int main() {
    for (int i = 0; i < 4; ++i) {
        // int n = rnd.next(1, 1000);
        // int m = rnd.next(1, 1000);
        int n, m;
        n = m = 1000;
        Array2d a = Array2d(n);
        for (auto &x : a) {
            x = Array::random(m, 1, 1e9);
        }
        cout << a.printN().printM().println();
    }
    return 0;
}
