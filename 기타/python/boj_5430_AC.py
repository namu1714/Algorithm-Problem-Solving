T = int(input())

for _ in range(T):
    p = input()
    n = int(input())
    numStr = input()

    arr = []
    if numStr != "[]":
        arr = numStr.strip('[]').split(',')

    isReverse = False
    isError = False
    start, end = 0, len(arr)
    
    for cmd in p:
        if cmd == 'D':
            if start >= end:
                isError = True
                break
            if isReverse == True:
                end -= 1
            else:
                start += 1

        elif cmd == 'R':
            isReverse = not isReverse

    if isError == True:
        print("error")
    else:
        print("[", end='')
        if isReverse == True:
            for i in range(end-1, start-1, -1):
                print(arr[i], end='')
                if i != start:
                    print(',', end='')
        else:
            for i in range(start, end):
                print(arr[i], end='')
                if i != end - 1:
                    print(',', end='')
        print("]")