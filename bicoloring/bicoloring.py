N = int(input())
E = int(input())

edges = []

for i in range(E):
    edges.append(list(map(int, input().split())))

colored = []
for i in range(N):
    colored.append(None)

# colored[edges[0][0]] = 'black'
# colored[edges[0][1]] = 'red'
incorrect = False
for edge in edges:
    if colored[edge[0]] == None and colored[edge[1]] == None:
        colored[edge[0]] = 'black'
        colored[edge[1]] = 'red'
    elif colored[edge[0]] == None:
        if colored[edge[1]] == 'black':
            colored[edge[0]] = 'red'
        elif colored[edge[1]] == 'red':
            colored[edge[0]] = 'black'
    elif colored[edge[1]] == None:
        if colored[edge[0]] == 'black':
            colored[edge[1]] = 'red'
        elif colored[edge[0]] == 'red':
            colored[edge[1]] = 'black'
    else:
        if colored[edge[0]] == colored[edge[1]]:
            incorrect = True
            break

if incorrect:
    print("NOT BICOLORING")
else:
    print("BICOLORING")
