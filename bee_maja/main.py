global_x = [0]*120100
global_y = [0]*120100
counter = 2


def updateCounter(x, y):
    global counter
    global_x[counter] = x[0]
    global_y[counter] = y[0]
    counter += 1


def up(x, y):
    y[0] -= 1
    updateCounter(x, y)


def upRight(x, y):
    x[0] += 1
    y[0] = -1
    updateCounter(x, y)


def downRight(x, y):
    x[0] += 1
    updateCounter(x, y)


def down(x, y):
    y[0] += 1
    updateCounter(x, y)


def downLeft(x, y):
    x[0] -= 1
    y[0] += 1
    updateCounter(x, y)


def upLeft(x, y):
    x[0] -= 1
    updateCounter(x, y)


x = [0]
y = [0]
global_x[1] = 0
global_y[1] = 0
for i in range(1, 184):
    down(x, y)
    for j in range(1, i):
        downLeft(x, y)
    for j in range(i):
        upLeft(x, y)
    for j in range(i):
        up(x, y)
    for j in range(i):
        upRight(x, y)
    for j in range(i):
        downRight(x, y)
    for j in range(i):
        down(x, y)
while True:
    query = input()
    if query == "":
        break
    query = int(query)
    print(global_x[query], global_y[query])
