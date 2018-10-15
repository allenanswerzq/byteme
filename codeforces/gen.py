import numpy as np

a = 3
for i in range(3):
  if a ^ i == a - i:
    print(a, i)
