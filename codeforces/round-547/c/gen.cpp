#include "array.h"
using namespace std;

int main() {
    freopen("test.rel", "w", stderr);
    freopen("ins.in", "w", stdout);
    for (int i = 0; i < 5; ++i) {
        int n = rnd.next(2, (int)10);
        // int n = (int)2e5;
        Array a = Array::id(n, 1).shuffle();
        Array d(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            d[i] = a[i + 1] - a[i];
        }
        cerr << a << endl;
        cout << n << endl;
        cout << d.println();
    }

    for (int i = 0; i < 5; ++i) {
        int n = rnd.next(2, (int)10);
        // int n = (int)2e5;
        Array a = Array::random(n, -n + 1, n - 1);
        Array d(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            d[i] = a[i + 1] - a[i];
        }
        cerr << -1 << endl;
        cout << n << endl;
        cout << d.println();
    }


    return 0;
}
