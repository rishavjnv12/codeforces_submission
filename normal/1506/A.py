for i in range(int(input())):
	n,m,x = map(int,input().split())
	x -= 1
	i = x//n
	j = x%n
	# print(i,j)
	print(m*j+i+1)