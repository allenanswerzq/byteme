import random as rd

def output(aa):
    for i, a in enumerate(aa):
        print(a, end='')
        if (i < len(aa) - 1): print(' ', end='')
        else: print('\n', end='')

n, m = 100000, 100000
# n, m = 50, 200

print(n, m)

a = [rd.randint(1, int(1e7)) for i in range(n)]
c = [rd.randint(1, int(1e6)) for i in range(n)]
output(a)
output(c)

for i in range(m):
    ix, needs = rd.randint(1, n), rd.randint(1, int(1e7))
    print(ix, needs)
