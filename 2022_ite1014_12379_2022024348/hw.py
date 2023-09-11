import random
x=[]
M=0

for i in range(1,15):
	y=random.randint(1,20)
	x.append(y)
for j in range(0,14):
	print(x[j],end=' ')
print('')
