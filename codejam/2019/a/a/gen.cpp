#include "array.h"
using namespace std;

int main() {
    int t = 4;
    cout << t << endl;
    for (int i = 0; i < t; ++i) {
        int n = 1e5, p = 1e5;
        Array a = Array::random(n, 1, 1e4);
        cout << n << " " << p << endl;
        cout << a << endl;
    }
    return 0;
}
