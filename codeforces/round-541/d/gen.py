import sys
import random as rd


def printn(s):
    print(s, end='')

def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

for t in range(10):
    n = rd.randint(1, 1000)
    m = rd.randint(1, 1000)
    # n, m = 2, 3
    print(n, m)
    nn = [rd.randint(1, 10) for i in range(n)]
    mm = [rd.randint(1, 10) for i in range(m)]
    # eprint(nn, mm)
    for i in range(n):
        for j in range(m):
            if nn[i] > mm[j]:
                if (t < 6): printn('>')
                else: printn('=')
            elif nn[i] == mm[j]:
                printn('>')
            elif nn[i] < mm[j]:
                printn('=')
        printn('\n')
    printn('\n')
