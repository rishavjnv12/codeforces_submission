n = int(input())
ans = [2 for i in range(n//2)]
if n%2:
    ans[-1] = 3
print(n//2)
for x in ans:
    print(x,end=" ")