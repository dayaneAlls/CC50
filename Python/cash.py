import cs50

#ask and check the input
while True:
    cash = cs50.get_float("Change owed: ")
    if cash >=0:break
      
#calculations to return minimum coin possibilities
cash2 = cash*100;
cent1 = cash2//25;
cent2 = (cash2 - cent1*25)//10
cent3 = (cash2 - cent1*25 - cent2*10)//5
cent4 = (cash2 - cent1*25 - cent2*10 - cent3*5)
total = cent1 + cent2 + cent3 + cent4

print(int(total))
print()
