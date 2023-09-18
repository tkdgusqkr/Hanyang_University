y=[0,1]
while 1:
	print('*'*13,'\n1.Calculate','\n2.Show it!','\n3.Initialize','\n4.Quit','\n'+'*'*13)
	a=int(input('Input : '))
	if a==1:
		c=int(input('Input the number : '))
		i=0
		f=y[len(y)-1]
		if len(y)==2:
			while i<c-2:
				f+=y[len(y)-2]
				y.append(f)
				i+=1
		else:
			while i<c:
				f+=y[len(y)-2]
				y.append(f)
				i+=1
	elif a==2:
		for j in range(len(y)):
			print(y[j],end=' ')
		print('')
	elif a==3:
		y=[0,1]
	elif a==4:
		break
		
		