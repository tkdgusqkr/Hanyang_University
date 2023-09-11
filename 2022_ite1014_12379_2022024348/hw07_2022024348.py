x=list(map(str,input("Input first string : ").split()))
y=list(map(str,input("Input second string : ").split()))
n=len(x)
k=0
while 1:
	if x==y:
		print("Circular string to right 0 time.")
		break
	else:
		k+=1
		z=[]
		z.append(x[n-1])
		for i in range(n-1):
			z.append(x[i])
		x=z
		if x==y:
			print("Circular string to right",k,"time")
			break
		elif k>len(y):
			print("Not circular identical!")
			break
		
		
		

