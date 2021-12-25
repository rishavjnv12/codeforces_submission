def solve():
    s = input()
    big,small,ans = 0,0,0
    for c in s:
        if c == '(':
            small += 1
        elif c == ')':
            if small > 0:
                ans += 1
                small -= 1
        elif c == '[':
            big += 1
        else:
            if big > 0:
                ans += 1
                big -= 1
    print(ans)

for _ in range(int(input())):
    solve()