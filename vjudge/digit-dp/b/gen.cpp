#include "array.h"
using namespace std;

#define ll long long

int main() {
    int T = 10000;
    cout << T << endl;
    for (int t = 0; t < T; ++t) {
        ll mx = (1ll << 62);
        ll a = rnd.next(1ll, mx);
        ll b = rnd.next(1ll, mx);
        // int k = rnd.next(1, 10);
        int k = 2;
        if (a > b) swap(a, b);
        cout << a << " " << b << " " << k << endl;
    }
    return 0;
}
