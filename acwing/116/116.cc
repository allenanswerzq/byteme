
def comp(li): return li[0] * li[1]

n = int(input())
mul, _ = map(int, input().split())
a = []
for i in range(n):
    a.append(list(map(int, input().split())))
a.sort(key=comp)
ans = 0
for i in range(n):
    ans = max(ans, mul)
    mul *= a[i][0]
print(ans)
