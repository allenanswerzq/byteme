import random as rd

t = 10
for i in range(t):
    n = rd.randint(2, 100)
    print(n)
    for j in range(n):
        x = rd.randint(1, int(1e9))
        print(x, end=' ')
    print("\n")
