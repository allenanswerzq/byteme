import collections

def find(A, k):
    if k > 0:
        return len(set(A) & set([n + k for n in A]))
    elif k == 0:
        return sum([v > 1 for v in collections.Counter(A).values()])


if __name__ == "__main__":
    print find([3, 1, 4, 1, 5], 2)
    print find([1, 2, 3, 4, 5], 1)
    print find([1, 3, 1, 5, 4], 0)

