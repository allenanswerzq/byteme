#include "rnds.h"
using namespace std;

int main() {
    int T = 100;
    cout << T << endl;
    for (int t = 0; t < T; ++t) {
        cout << 10 << " " << 10 << endl;
        for (int i = 0; i < 10; ++i) {
            string a = rnds.random(10, "01");
            cout << a << endl;
        }
    }
    return 0;
}
