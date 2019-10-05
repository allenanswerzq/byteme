#include "graph.h"
using namespace std;

int main() {
    for (int i = 0; i < 4; ++i) {
        int n = rnd.next(2, int(2e5));
        int k = rnd.next(2, 100);
        // int n = 3, k = 3;
        cout << n << " " << k << endl;
        Graph g = Graph::random(n, n - 1);
        WeightArray w = Array::random(n - 1, 0, 1);
        g.setEdgeWeights(w);
        cout << g.add1().println();
    }
    return 0;
}
