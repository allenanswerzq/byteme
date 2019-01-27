
def fun(x):
    a = str(x)
    if (len(a) == 1):
        return int(a[0])
    x = sum([int(x) for x in a], 0)
    return fun(x)

for i in range(1, 100):
    print(i, fun(i))
