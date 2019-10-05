#include "array.h"
using namespace std;

void large() {
    // Large tests.
    for (int i = 0; i < 10; ++i) {
        int n = rnd.next(1, (int)1e6);
        int m = rnd.next(1, (int)1e3);
        int r = rnd.next(1, n);
        cout << n << " " << m << " " << r << endl;
        for (int i = 0; i < m; ++i) {
            int s = rnd.next(1, n);
            int e = rnd.next(s, n);
            int w = rnd.next(1, (int)1e6);
            cout << s << " " << e << " " << w << endl;
        }
        cout << endl;
    }
}

void small() {
    // Small tests.
    for (int i = 0; i < 10; ++i) {
        int n = rnd.next(1, 3);
        int m = rnd.next(1, 3);
        int r = rnd.next(1, n);
        cout << n << " " << m << " " << r << endl;
        for (int i = 0; i < m; ++i) {
            int s = rnd.next(1, n);
            int e = rnd.next(s, n);
            int w = rnd.next(1, (int)1e6);
            cout << s << " " << e << " " << w << endl;
        }
        cout << endl;
    }
}

int main() {
    large();
    small();
    return 0;
}
