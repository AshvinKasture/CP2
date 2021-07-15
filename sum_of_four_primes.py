n = int(input())

lst = []

for i in range(0, n):
    if i > 1:
        for j in range(2, i):
            if(i % j == 0):
                break
        else:
            lst.append(i)

# print(lst)
lst2 = []
gotAnswer = False
answer = None
for n1 in lst:
    for n2 in lst:
        for n3 in lst:
            for n4 in lst:
                x = n1+n2+n3+n4
                if(n == x and not gotAnswer):
                    print("{} {} {} {}".format(n1, n2, n3, n4))
                    answer = (n1, n2, n3, n4)
                    gotAnswer = True
                    break

print(answer)
