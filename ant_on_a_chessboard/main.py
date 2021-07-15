from math import sqrt, ceil


while True:
    n = int(input())
    if n == 0:
        break

    r = ceil(sqrt(n))
    diff = r*r-n
    k = (2*r)-1
    k1 = k//2
    if r % 2 == 1:
        if diff > k1:
            x = r
            y = k - diff
        else:
            y = r
            x = diff+1
    else:
        if diff > k1:
            y = r
            x = k-diff
        else:
            x = r
            y = diff+1
    print(x, y)



