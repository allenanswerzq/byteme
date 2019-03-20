#include "array.h"
using namespace std;

int main() {
    for (int i = 0; i < 10; ++i) {
        int n = rnd.next(1, 100);
        int k = rnd.next(1, 100);
        // int n = 3, k = 1;
        cout << n << " " << k << endl;
        Array2d a = Array2d(n, Array(n));
        for (auto &t : a) {
            t = Array::random(n, 1, 100);
        }
        cout << a.println() << endl;
    }
    return 0;
}
