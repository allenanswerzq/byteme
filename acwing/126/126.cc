
def get(c):
  if '0' <= c and c <= '9':
    return int(c)
  elif 'A' <= c and c <= 'Z':
    return ord(c) - ord('A') + 10
  else:
    return ord(c) - ord('a') + 36

def to_str(c):
  if 0 <= c and c <= 9:
    return str(c)
  elif 10 <= c and c <= 35:
    return chr(ord('A') + c - 10)
  else:
    return chr(ord('a') + c - 36)

def solve(i, n):
  n, m, s = input().split()
  n, m = int(n), int(m)

  a = 0
  for c in s:
    a *= n
    a += get(c)

  r = ""
  ok = True
  while ok:
    x = a % m
    a = a // m
    r = r + to_str(x)
    ok = (a > 0)

  print(n, s)
  print(m, r[::-1])
  print()

n = int(input())
for i in range(n):
  solve(i, n)
