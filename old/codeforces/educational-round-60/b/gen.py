# s 𝑛,𝑚 and 𝑘 (2≤𝑛≤2⋅105, 1≤𝑘≤𝑚≤2⋅109) —
import random as rd

n = rd.randint(2, int(2 * 1e5))
m = rd.randint(1, int(2 * 1e9))
k = rd.randint(1, int(2 * 1e9))
# n, m, k = 6, 9, 2
print(n, m, k)
for i in range(n):
    a = rd.randint(1, int(1 * 1e9))
    print(a, end=' ')
print()
