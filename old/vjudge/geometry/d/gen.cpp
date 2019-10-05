#include "array.h"
using namespace std;

int main() {
    int T = 1000;
    cout << T << endl;
    for (int t = 0; t < T; ++t) {
        Array a = Array::random(8, -10, 10);
        cout << a << endl;
    }
    return 0;
}
