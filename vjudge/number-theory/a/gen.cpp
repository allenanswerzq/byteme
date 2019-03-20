#include "array.h"
using namespace std;

int main() {
    int t = 100;
    cout << t << endl;
    for (int i = 0; i < t; ++i) {
        int n = rnd.next(1, (int)1e4);
        // int n = 3;
        Array a = Array::random(n, 1, 1e6);
        cout << a.printN() << endl;
    }
    return 0;
}
