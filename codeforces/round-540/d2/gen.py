import random as rd

t = 10
for j in range(t):
    n = rd.randint(1, int(2 * 1e5))
    m = rd.randint(1, int(1e9))
    # n, m = 5, 8
    print(n, m)
    for i in range(n):
        x = rd.randint(1, int(1e9))
        print(x, end=' ')
    print('\n')
