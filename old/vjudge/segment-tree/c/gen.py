import random
N, Q = 100000, 100000
# N, Q = 4, 3
MIN, MAX = -1000000000, 1000000000
CMIN, CMAX = -10000, 10000
print(N, Q)
for i in range(N):
    x = random.randint(MIN, MAX)
    if i < N - 1: print(x, end=' ')
    else: print(x)

query = 0
for i in range(Q):
    ch = random.randint(MIN, MAX)
    a = random.randint(1, N)
    b = random.randint(1, N)
    if a > b: a, b = b, a
    if ch % 2:
        # update a, b, c
        c = random.randint(CMIN, CMAX)
        print('C', a, b, c)
    else:
        query += 1
        print('Q', a, b)

if query == 0:
    a = random.randint(1, N)
    b = random.randint(1, N)
    if a > b: a, b = b, a
    print('Q', a, b)
