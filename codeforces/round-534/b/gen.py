import random
N = 100
for i in range(4):
    x = random.choices([chr(ord('a') + i) for i in range(2)], k = random.randint(1, N))
    print(''.join(s for s in x))
    print('')
