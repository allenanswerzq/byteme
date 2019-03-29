#include "array.h"
using namespace std;

int main() {
    int T = 1000;
    for (int t = 0; t < T; ++t) {
        int n = rnd.next(1, 1000);
        cout << n << endl;
        for (int i = 0; i < n; ++i) {
            Arrayf a = Arrayf::random(4, -2, 2);
            cout << a << endl;
        }
    }
    cout << 0 << endl;
    return 0;
}
