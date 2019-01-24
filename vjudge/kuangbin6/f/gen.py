import random
N = 2000
for i in range(N):
    s = random.choices([chr(ord('a') + i) for i in range(26)], k = 7)
    print(''.join(x for x in s))

