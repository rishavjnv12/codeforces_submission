def next(p,a):
    d = p//a
    if d*a == p:
        return p
    return (d+1)*a

for _ in range(int(input())):
    p,a,b,c = map(int,input().split())
    a1,a2,a3 = next(p,a),next(p,b),next(p,c)
    print(min(a1-p,a2-p,a3-p))