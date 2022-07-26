import cs50

while True:
    h = cs50.get_int("Height: ")
    if h > 0 and h <= 8:
        break
for i in range(h):
    for j in range(h):
        if i + j < h - 1:
            print(" ",end='')
        else:
            print("#",end='')
    print()
