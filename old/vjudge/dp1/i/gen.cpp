#include "array.h"
using namespace std;

int main() {
    for (int i = 0; i < 10; ++i) {
        int n = rnd.next(10);
        Array a = Array::random(n, 1, 10);
        cout << a.printN().println() << endl;
    }
    return 0;
}
