for _ in range(int(input())):
    n,k = map(int,input().split())
    if n is 1:
        if k == 1:
            print('0')
            continue
        else:
            print('1\n1\n')
            continue
    
    ans = [i for i in range(k+1,n+1)]
    if k != 1:
        ans = [k-1] + ans
    print(len(ans))
    for x in ans:
        print(x,end=' ')
    print()