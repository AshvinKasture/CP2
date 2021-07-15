def readcase():
    return input(), input()


def nmatches_table(txt, pat):
    t, p = len(txt), len(pat)
    dp = [[0 for _ in range(t+1)] for _ in range(p+1)]
    for i in range(len(dp[0])):
        dp[0][i] = 1

    for ip in range(p):
        matches = 0
        for it in range(ip, t):
            if txt[it] == pat[ip]:
                matches += dp[ip][it]
            dp[ip+1][it+1] = matches

    return max(dp[-1])


if __name__ == '__main__':

    ncases = int(input())

    solutions = []
    for c in range(ncases):
        text, pattern = readcase()
        solutions.append(nmatches_table(text, pattern))
    print("\n".join(map(str, solutions)))
