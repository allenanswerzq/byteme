#include "array.h"
using namespace std;

int main() {
    cout << 100 << endl;
    for (int t = 0; t < 100; ++t) {
        int n = 2e4;
        int k = 5e4;
        Array a = Array::random(n, 1, 1e9);
        cout << n << " " << k << endl;
        cout << a << endl;
    }
    return 0;
}
