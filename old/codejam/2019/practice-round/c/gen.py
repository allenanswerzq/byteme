# 1 ≤ T ≤ 100.
# Time limit: 90 seconds per test set.
# Memory limit: 1 GB.
# 1 ≤ x1 ≤ 105.
# 1 ≤ y1 ≤ 105
# 1 ≤ C ≤ 105.
# 1 ≤ D ≤ 105.
# 1 ≤ E1 ≤ 105.
# 1 ≤ E2 ≤ 105.
# 1 ≤ F ≤ 105.

# Small dataset (Test set 1 - Visible)
# 1 ≤ N ≤ 100.
# 1 ≤ K ≤ 20.
import random as rd
TMIN, TMAX = 1, 100
MIN, MAX = 1, int(1e5)
T = rd.randint(TMIN, TMAX)
print(T)
for i in range(T):
    N = rd.randint(1, 100)
    K = rd.randint(20, 20)
    x1 = rd.randint(MIN, MAX)
    y1 = rd.randint(MIN, MAX)
    C = rd.randint(MIN, MAX)
    D = rd.randint(MIN, MAX)
    E1 = rd.randint(MIN, MAX)
    E2 = rd.randint(MIN, MAX)
    F = rd.randint(MIN, MAX)
    print(N, K, x1, y1, C, D, E1, E2, F)
