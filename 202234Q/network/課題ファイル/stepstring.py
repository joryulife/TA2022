n = int(input())
str = list(input())
i = 0
if n < 0:
    str = str[::-1]

if n == 0:
    print(''.join(str))
else :
    for s in str:
        if i % n == 0:
            print(s, end="")
        i += 1