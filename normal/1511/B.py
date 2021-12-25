for _ in range(int(input())):
    a,b,c = map(int,input().split())
    if c == min(a,b):
        print(10**(a-1),10**(b-1))
        continue
    elif a < b:
        x = [5 for i in range(a)]
        x[0] = 3
        idx,cnt = -1,0
        while cnt < c-1:
            x[idx] = 0
            cnt += 1
            idx -= 1
        x = list(map(str,x))
        y = 10**(b-1)
        print(''.join(x),y)
    else:
        a,b = b,a
        x = [5 for i in range(a)]
        x[0] = 3
        idx, cnt = -1, 0
        while cnt < c - 1:
            x[idx] = 0
            cnt += 1
            idx -= 1
        x = list(map(str, x))
        y = 10 ** (b - 1)
        print(y,''.join(x))