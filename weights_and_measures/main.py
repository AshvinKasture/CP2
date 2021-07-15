allTurtles = []

while True:
    ip = input()
    if ip == '':
        break
    weight, strength = map(int, ip.split())
    allTurtles.append((weight, strength))

print(allTurtles)

for i in range(len(allTurtles)-1):
    for j in range(i+1, len(allTurtles)):
        if allTurtles[j][0] < allTurtles[i][0]:
            allTurtles[i], allTurtles[j] = allTurtles[j], allTurtles[i]

print(allTurtles)

finalList = []

totalWeight = 0

for turtle in allTurtles:
    totalWeight += turtle[0]
    if totalWeight > turtle[1]:
        totalWeight -= turtle[0]
    else:
        finalList.append(turtle)

print(len(finalList))
