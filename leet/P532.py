
def solve2(A, k):
    A = sorted(A)
    i, j = 0, 0
    unique = 0
    
    while i < len(A):
        j = max(j, i+1)
        while j < len(A) and A[j] - A[i] < k:
            j += 1
        if j < len(A) and A[j] - A[i] == k:
            unique += 1
        while i+1 < len(A) and A[i] == A[i+1]:
            i += 1
        i += 1
    return unique

def solve(A, k):
    d = {}
    unique = 0
    for a in A:
        d[a] = 0
    
    for a in A:
        d[a] += 1

    if k == 0:
        for a in A:
            if d[a] >= 2:
                unique += 1
    else:
        for a in d:
            if a+k in d:
                unique += 1
    return unique
    

if __name__ == "__main__":
    print solve([3, 1, 4, 1, 5], 2)
    print solve([1, 2, 3, 4, 5], 1)
    print solve([1, 3, 1, 5, 4], 0)
    print solve([1, 1, 1, 2, 1], 1)
