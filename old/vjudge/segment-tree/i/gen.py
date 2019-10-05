import random as rd
n, m = 50000, 50000
a, b = 0, 0
print(n, m)
for i in range(m):
    op = rd.randint(0, 2)
    if op == 0:
        a += 1
        x = rd.randint(1, n)
        print('D', x)
    elif op == 1:
        b += 1
        x = rd.randint(1, n)
        print('Q', x)
    elif op == 2:
        if a > 0:
            print('R')
        else:
            a += 1
            x = rd.randint(1, n)
            print('D', x)

