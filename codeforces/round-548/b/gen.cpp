#include "array.h"
using namespace std;

int main() {
    for (int i = 0; i < 10; ++i) {
        int n = 2e5;
        Array a = Array::random(n, 1, 1e9);
        cout << a.printN().println();
    }
    return 0;
}
