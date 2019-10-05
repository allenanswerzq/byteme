#include "graph.h"
using namespace std;

int main() {
    for (int i = 0; i < 4; ++i) {
        int inf = (int)2e5;
        int n = rnd.next(2, inf);
        int m = rnd.next(n - 1, min(inf, n * (n - 1) / 2));
        // int d = rnd.next(1, n - 1);
        Graph g = Graph::random(n, m).connected();
        int d = rnd.next(1, (int)g.edges(0).size());
        cout << n << " " << m << " " << d << "\n";
        cout << g.add1() << "\n\n";
    }
    return 0;
}
