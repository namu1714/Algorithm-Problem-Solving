import re

idArr = []
check = ['0', '0', '0', '0', '0', '0', '0', '0']

def dfs(n, user_id, expr):
    if n == len(expr):
        tmp = int("".join(check), 2)
        if tmp not in idArr:
            idArr.append(tmp)
        return

    for i in range(len(user_id)):
        if expr[n].match(user_id[i]) != None:
            if(check[i] == '0'):
                check[i] = '1'
                dfs(n+1, user_id, expr)
                check[i] = '0'

def solution(user_id, banned_id):
    expr = []

    for word in banned_id:
        expr.append(re.compile(word.replace("*", ".") + '$'))

    dfs(0, user_id, expr)

    return len(idArr)
