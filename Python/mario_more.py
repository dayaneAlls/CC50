import cs50

#check user input
while True:
    h = cs50.get_int("Height: ")
    if h > 0 and h <= 8:break

#prints the # according to the size specified by the user 'h'
for i in range(h):
    for j in range(h):
        if i + j < h - 1:
            print(" ",end='')
        else:
            print("#",end='')
    print("  ",end='')
    #range(start, end, step)
    for j in range(h, 0, -1):
        if j + i > h - 1:
            print("#",end='')
        else:
            print(" ",end='')
    print()
