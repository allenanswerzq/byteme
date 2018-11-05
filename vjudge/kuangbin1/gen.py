
# n, k, d = map(int, input().split())

N = 101
S = 1
for a in range(S, N):
  for b in range(S, N):
    for c in range(1, max(a, b) + 1):
      print(a, b, c)
      print() 
      print(b, a, c);
      print()