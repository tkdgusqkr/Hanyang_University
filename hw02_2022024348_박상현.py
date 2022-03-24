line=0
number=int(input('number:'))
while line<number:
	print(' '*(number-line),'*'*(2*line+1))
	line+=1

