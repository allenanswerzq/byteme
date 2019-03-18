#include "graph.h"
using namespace std;

int main() {
    for (int i = 0; i < 4; ++i) {
        Graph g = Graph::random(3, 2, 10);
        // WeightArray w = Array::random(2, 10);
        // g.setEdgeWeights(w);
        cout << g.printN().printM().println() << endl;
    }
    return 0;
}
