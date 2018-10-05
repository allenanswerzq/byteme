import numpy as np

# // ll ret = 0;
# // int x, y;
# // fori (i, 0, n) {
# //   fori (j, 0, n) {
# //     if (i + j == n) {
# //       int tmp = cal(i) + cal(j);
# //       if (ret < tmp) {
# //         x = i; y = j;
# //         ret = tmp;
# //       }
# //     }
# //   } 
# // }
# // trace(x, y);
# // outret(ret);

def cal(aa):
  ret = 0
  for a in str(aa):
    ret += a - '0'
  return ret

n = 1000
ret = 0
for i in range(n):
  for j in range(n):
    if i + j == n:
      ret = max(ret, cal(i) + cal(j))

print(ret)
