
# n, k, d = map(int, input().split())

n = 100
for i in range(1, n + 1):
  r = 1**i + 2**i + 3**i + 4**i
  print(i, r, r % 5)


