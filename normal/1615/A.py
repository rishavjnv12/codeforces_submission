for _ in range(int(input())):
    n = int(input())
    print(1 if sum(list(map(int,input().split())))%n else 0)