import random
x=[]
M=0

for i in range(1,100):
	y=random.randint(1,1000)
	x.append(y)
for j in range(0,99):
	print(x[j],end=' ')
for k in range(0,99):
	for n in range(0,99):
		if x[k]>=x[n]:
			x[n]=x[k]
print('\nMaximum number is ',x[0])
