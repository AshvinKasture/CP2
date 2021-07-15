MAXCANDIDATES = 5

finished = False


def is_a_solution(a, k, n):
    return k == n


def construct_candidates(a, k, n, c, ncandidates):
    c[0] = 1
    c[1] = 0
    ncandidates[0] = 2


def process_solution(a, k):
    print("{ ", end='')
    for i in range(1, k+1):
        if a[i] == True:
            print(i, end=" ")
    print(" }")


def backtrack(a, k, input):
    c = [0]*MAXCANDIDATES
    ncandidates = [0]
    if(is_a_solution(a, k, input)):
        process_solution(a, k)
    else:
        k += 1
        construct_candidates(a, k, input, c, ncandidates)
        for i in range(ncandidates[0]):
            a[k] = c[i]
            backtrack(a, k, input)
            if(finished):
                return


a = [1, 2, 3]

backtrack(1, 0, 3)
