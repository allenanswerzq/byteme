#include "array.h"
using namespace std;

int main() {
    int t = rnd.next(1, 20);
    cout << t << endl;
    for (int i = 0; i < t; ++i) {
        int n = rnd.next(1, (int)4e4);
        Array a = Array::random(n, 1, 5e5);
        cout << a.printN() << endl;
    }
    return 0;
}
