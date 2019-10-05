import random as rd
maxn, maxb = int(1e18), int(1e12)

for i in range(100):
    n = rd.randint(1, maxn)
    b = rd.randint(2, maxb)
    print(n, b)
    print()
