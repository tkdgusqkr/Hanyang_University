def F(i):
	if i>=2:
		return F(i-1)+F(i-2)
	elif i==0 or i==1:
		return i
num=int(input("Input the number : "))
print(num,"th fibonacci number is",F(num))	
	
