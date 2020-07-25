n, l, r = map(int, input().split())
# print(n, l, r)

a = list(map(int, input().split()))
b = list(map(int, input().split()))
# print(a, b)
l -= 1
r -= 1
ma, mb = [], []
for i in range(0, n):
  if not (l <= i and i <= r):
    if a[i] != b[i]:
      print("LIE")
      exit(0)
  else:
    ma.append(a[i])
    mb.append(b[i])

ma.sort()
mb.sort()

if ma == mb:
  print("TRUTH")
else:
  print("LIE")

