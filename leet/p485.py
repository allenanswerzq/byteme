
def find(A):
    cnt, t = 0, 0
    for a in A:
        if a == 1:
            t += 1
            cnt = max(cnt, t)
        else:
            t = 0
    return cnt

def find2(A):
    m, i, j = 0, 0, 0
    t = 0
    
    while i < len(A):
        if A[i] == 0:
            t = 0
            while i+1 < len(A) and A[i+1] == 1:
                t += 1
                i += 1
            i += 1
        elif A[i] == 1:
            t = 0
            while i<len(A) and A[i] == 1:
                i += 1
                t += 1
        if t > m:
            m = t
    return m

if __name__ == "__main__":
    print find([1, 0, 1, 1, 0, 1])
    print find([1, 0, 1, 1, 1, 1])
    print find([1, 1, 1, 1, 0, 1])
            

