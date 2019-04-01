#include "array.h"
using namespace std;

#define ll long long
int main() {
    int T = 1000;
    cout << T << endl;
    for (int t = 0; t < T; ++t) {
        ll a = rnd.next(1ll, (1ll << 63) - 1);
        cout << a << endl;
    }
    return 0;
}
