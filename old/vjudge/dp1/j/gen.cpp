#include "array.h"
using namespace std;

int main() {
    for (int i = 0; i < 10; ++i) {
        int n = rnd.next(1, 3);
        for (int j = 0; j < n; ++j) {
            Array a = Array::random(2, 1, 1e4);
            cout << a << endl;
        }
        cout << endl;
    }
    return 0;
}
