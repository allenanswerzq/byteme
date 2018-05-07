
def find(A):
    result = []
    n = len(A)
    for i in range(len(A)):
        A[ (A[i] - 1) % n ] += n
    print A
    for i in range(len(A)):
        if A[i] <= n:
            result.append(i+1)
    return result

def find3(A):
    result = []
    for i in range(len(A)):
        val = abs(A[i]) - 1
        if A[val] > 0:
            A[val] = -A[val]
    print A
    for i in range(len(A)):
        if A[i] > 0:
            result.append(i + 1)
    return result


def find2(A):
    m = [ 0 for i in range(len(A))]  # extra space
    result = []

    for i in range(len(A)):
        m[A[i] - 1] += 1

    for i in range(len(m)):
        if m[i] == 0:
            result.append(i+1)
    return result


if __name__ == "__main__":
    print find([4, 3, 2, 7, 8, 2, 3, 1])
