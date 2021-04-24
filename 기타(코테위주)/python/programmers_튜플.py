def solution(s):
    answer = []
    dic = dict()

    for sets in s[1:len(s)-1].split(","):
        for num in sets.strip("{}").split(","):
            if num not in dic.keys():
                dic[num]  = 1
            else:
                dic[num] += 1

    dic = sorted(dic.items(), key = lambda x : x[1], reverse=True)
    answer = [int(i[0]) for i in dic]

    return answer