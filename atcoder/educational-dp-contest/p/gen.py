from cyaron import *

for t in range(3):
    n = randint(1, int(1e5))
    print(n)
    g = Graph.DAG(n, n - 1)
    print(g.to_str())
    print()




