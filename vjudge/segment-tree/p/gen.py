import random as rd

T = rd.randint(1, 100)
def randxy():
    XMAX = 1e1
    return rd.random() * XMAX
# T = 1
print(T)
for i in range(T):
    N = rd.randint(1, 1000)
    print(N)
    for j in range(N):
        x1, y1 = randxy(), randxy()
        x2, y2 = randxy(), randxy()
        while not (x1 <= x2 and y1 <= y2):
            x1, y1 = randxy(), randxy()
            x2, y2 = randxy(), randxy()

        print("{0:.2f} {1:.2f} {2:.2f} {3:.2f}".format(x1, x2, y1, y2))

