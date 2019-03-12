from cyaron import *

for t in range(4):
    m = rint(1, 10)
    while 1:
        k = rint(1, 10)
        n = rint(1, 10)
        if n * k <= m: break
    s = rint(1, k)
    print(m, k, n, s)
    a = List.random(num=m, maxn=5e5)
    b = List.random(num=s, maxn=5e5)
    print(a)
    println(b)
