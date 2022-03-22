def Incr(hgt):
	line=1
	while line<=hgt:
		print("*"*line)
		line+=1
def Decr(hgt):
	line=1
	while line<=hgt:
		print("*"*(hgt-line+1))
		line+=1
number=int(input("number : "))
height=int(input("height : "))
if number==1:
	Incr(height)
elif number==2:
	Decr(height)
elif number==3:
	Incr(height)
	Decr(height-1)
elif number==4:
	i=0
	while i<10:
		Incr(height)
		Decr(height-1)
		i+=1
else:
	print("1~4 사이의 숫자를 골라주세요")