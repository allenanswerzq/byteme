import random as rd
C = 1
T, N = 100000, 100000
print(C)
print(T, N)
for i in range(N):
    op = rd.randint(1, 3)
    if op == 1:
        qt = rd.randint(1, 110000)
        print("DS", qt)
    elif op == 2:
        qt = rd.randint(1, 110000)
        print('NS', qt)
    else:
        b = rd.randint(1, T)
        e = rd.randint(1, T)
        if b > e: b, e = e, b
        print('STUDY!!', b, e)
