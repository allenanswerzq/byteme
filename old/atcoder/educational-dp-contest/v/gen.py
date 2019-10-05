from cyaron import *

for t in range(5):
    n = rint(1, 1e5)
    m = rint(1, 1e9)
    g = Graph.DAG(n, n - 1)
    print(n, m)
    println(g)

# n = int(1e5)
# print(n, int(1e9))
# for i in range(2, n + 1):
#     print(1, i)
# print()

