#include "graph.h"
using namespace std;

int main() {
    for (int i = 0; i < 2; ++i) {
        auto n = rnd.next(2, 10);
        auto m = n - 1;
        auto g = Graph(Graph::random(n, m).connected());
        cout << g.add1().printN().printM() << "\n\n";
    }
    return 0;
}


