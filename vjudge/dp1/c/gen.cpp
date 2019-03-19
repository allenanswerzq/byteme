#include "array.h"
using namespace std;

int main() {
    for (int i = 0; i < 4; ++i) {
        int bk = rnd.next(1, 100);
        cout << bk << endl;
        for (int b = 0; b < bk; ++b) {
            Array a = Array::random(3, 1, 100);
            cout << a << endl;
        }
    }
    cout << 0 << "\n";
    return 0;
}
