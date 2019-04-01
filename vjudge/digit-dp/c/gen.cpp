#include "array.h"
using namespace std;

int main() {
    int T = 100;
    for (int t = 0; t < T; ++t) {
        int a = rnd.next(1, (int)1e6);
        int b = rnd.next(1, (int)1e6);
        if (a > b) swap(a, b);
        cout << a << " " << b << endl;
    }
    cout << 0 << " " << 0 << endl;
    return 0;
}
