
# n, k, d = map(int, input().split())
d = 2 ** 32
tt = [t for t in range(1, 201)]

def check(a):
  while a:
    x, a = a % 10, a / 10
    if x > 1:
      return 0
  return 1

for t in tt:
  for i in xrange(1, d):
    if i % t == 0 and check(i):
      print(t, i)
      break

