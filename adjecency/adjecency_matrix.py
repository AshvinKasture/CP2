def print_matrix(matrix):
    print()
    for row in matrix:
        for item in row:
            print(item, end=' ')
        print()
    print()


def print_list(lst):
    for i in range(len(lst)):
        print(i, " -> ", end='')
        # print(lst[i])
        for item in lst[i]:
            print(item, end=' ')
        print()


N = int(input())
E = int(input())

edges = []
for i in range(E):
    edges.append(list(map(int, input().split())))


matrix = []

for i in range(N):
    lst = []
    for j in range(N):
        lst.append(0)
    matrix.append(lst)


for edge in edges:
    matrix[edge[0]][edge[1]] = 1
    matrix[edge[1]][edge[0]] = 1

print_matrix(matrix)


adjecency_list = []

for row in matrix:
    lst = []
    for i in range(len(row)):
        if row[i] == 1:
            lst.append(i)
    adjecency_list.append(lst)


print_list(adjecency_list)
