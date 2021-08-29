def solution(n, k, cmd):
    answer = ''
    table = {}
    stack = []

    for i in range(n):
        table[i] = [i-1, i+1, True]

    for c in cmd:
        if c[0] == 'U':
            for i in range(int(c[2:])):
                k = table[k][0]

        elif c[0] == 'D':
            for i in range(int(c[2:])):
                k = table[k][1]

        elif c[0] == 'C':
            delete = k
            k = table[k][1] if table[k][1] < n else table[k][0]

            if table[delete][0] >= 0:
                table[table[delete][0]][1] = table[delete][1]
            if table[delete][1] < n:
                table[table[delete][1]][0] = table[delete][0]

            stack.append(delete)
            table[delete][2] = False

        elif c[0] == 'Z':
            recover = stack.pop()
            if table[recover][0] >= 0:
                table[table[recover][0]][1] = recover
            if table[recover][1] < n:
                table[table[recover][1]][0] = recover
            table[recover][2] = True

    for i in range(n):
        if table[i][2] == True:
            answer += 'O'
        else:
            answer += 'X'

    return answer