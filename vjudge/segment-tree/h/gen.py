import random as rd
N, M = int(1e5), int(1e5)
# N, M = 3, 4
print(N)

x = [rd.randint(1, 2**32) for i in range(N)]
while sum(x) >= 2**63:
    x = [rd.randint(1, 2**32) for i in range(N)]

for i, a in enumerate(x):
    print(a, end='')
    if i < len(x) - 1: print(' ', end='')
    else: print('\n', end='')

print(M)

for i in range(M):
    op = rd.randint(0, 1)
    b = rd.randint(1, N)
    e = rd.randint(1, N)
    print(op, b, e)
