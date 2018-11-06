
# n, k, d = map(int, input().split())

N = 101
S = 1
for s in range(S, N):
  for a in range(1, s):
    if a + a <= s:
      print (s, a, s - a);
print(0, 0, 0)