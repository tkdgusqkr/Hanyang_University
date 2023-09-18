passc=0
failc=0
i=0
while i<10:
	i=i+1
	result=int(input('Enter result(1=pass,2=fail):'))
	if result==1:
		passc+=1
	elif result==2:
		failc+=1	
print('pass : ', passc)
print('fail : ', failc)