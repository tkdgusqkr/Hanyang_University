print('숫자입력(1~20)')
number=int(input())
if number<1:
	print('올바른 숫자를 입력해주세요.')
elif number>20:
	print('올바른 숫자를 입력해주세요.')
else:
	line=0
	while line<number:
		print('*'*(number-line))
		line+=1
