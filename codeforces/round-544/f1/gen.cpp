#include "graph.h"
using namespace std;

int main() {
    for (int i = 0; i < 10; ++i) {
        int inf = (int)2e5;
        auto n = rnd.next(2, inf);
        auto m = rnd.next(n - 1, min(inf, n * (n - 1) / 2));
        auto g = Graph(Graph::random(n, m).connected());
        cout << g.add1().printN().printM() << "\n\n";
    }
    return 0;
}


