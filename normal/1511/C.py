n,q = map(int,input().split())
a = list(map(int,input().split()))
q = list(map(int,input().split()))
ans = []
for x in q:
    for i in range(n):
        if a[i] == x:
            ans.append(i+1)
            idx = i
            while idx > 0:
                a[idx] = a[idx-1]
                idx -= 1
            a[0] = x
            break

for x in ans:
    print(x,end=' ')
print()