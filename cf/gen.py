import numpy as np

print("\n\n")
n = 100
print(n)
for i in range(n // 2):
  x = np.random.randint(100, size=1)[0]
  y = 200 - x
  print(x, y, end=' ')
