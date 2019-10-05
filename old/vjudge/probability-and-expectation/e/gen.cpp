#include "array.h"
using namespace std;

int main() {
    int T = (int)2e4;
    cout << T << endl;
    for (int i = 0; i < T; ++i) {
        auto x = rnd.next(1, (int)1e5);
        cout << x << endl;
    }
    cout << endl;
    return 0;
}
