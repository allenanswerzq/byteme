#include "array.h"
using namespace std;

int main() {
    for (int i = 0; i < 4; ++i) {
        int n = rnd.next(2, (int)1e5);
        Array a = Array::random(n, 1, 2);
        cout << n << "\n";
        cout << a << "\n\n";
    }
    return 0;
}
