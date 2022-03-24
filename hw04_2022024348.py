def GCD(num1, num2): 
	if num1 < num2: 
		(num1, num2) = (num1, num2) 
	while num2 != 0: 
		(num1, num2) = (num2, num1 % num2) 
	return num1
def LCM(num1, num2):
    return num1 * num2 // GCD(num1, num2)

num1=int(input("숫자를 입력하시오 : "))
num2=int(input("숫자를 입력하시오 : "))
print("Greatest common divisor : ",GCD(num1,num2))
print("Least common multiple : ",LCM(num1,num2))
		
			
		
		