import numpy as np

def check(aa):
  if aa == 1: return 0
  for i in range(2, aa):
    if (aa % i) == 0:
      return 0
  return 1

n = int(input()) 
for i in range(n):
  arr = [int(x) for x in input().split()] 
  a, b = arr 
  print(a + b, a - b)

