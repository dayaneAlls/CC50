import cs50

#check input
num = cs50.get_int("Number: ")

#define variables
aux1, som, aux = 0, 0, 0

#convert int input to string, cut first 2 digits and convert back to int
n = str(num)
cod = int(n[ :2])

#calculates card digits according to Luhn's algorithm
while num > 0:
    aux1 += num % 10
    aux = ((num //10)%10)*2
    som += (aux//10 + aux%10)
    num = (num //10)//10
total = (aux1+som)%10

#check if it is valid and print result
if total == 0 and (cod == 34 or cod == 37):
    print("AMEX")
elif total == 0 and (cod >= 51 and cod <= 55):
    print("MASTERCARD")
elif total == 0 and cod//10 == 4:
    print("VISA")
else:
    print("INVALID")
