import random as rd

def printn(x):
    print(x, end=' ')

T = 10
for t in range(T):
    n = rd.randint(1, int(1e5))
    aa = [x for x in range(1, n + 1)]
    bb = [x for x in range(1, n + 1)]
    rd.shuffle(aa)
    rd.shuffle(bb)
    print(n)
    aa += bb

    for a in aa:
        printn(a)
    print('\n')

