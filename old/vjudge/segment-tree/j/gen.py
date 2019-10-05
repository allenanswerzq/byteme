import random as rd
T = 1
N = 50000
print(T)
print(N)
for i in range(N - 1):
    print(i + 1, i + 2)
M = 50000
print(M)
for i in range(M):
    op = rd.randint(1, 2)
    if op == 1:
        x = rd.randint(1, N)
        print('C', x)
    elif op == 2:
        x = rd.randint(1, N)
        y = rd.randint(0, int(1e9))
        print('T', x, y)

