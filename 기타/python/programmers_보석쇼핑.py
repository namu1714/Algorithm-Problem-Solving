def solution(gems):
    answer = [1, len(gems)]

    dic = dict()
    
    total = len(set(gems))
    start, end = 0, 0
    
    while end <= len(gems):
        if len(dic) == total:
            if end - start - 1 < answer[1] - answer[0]:
                answer = [start + 1, end]

            if dic[gems[start]] <= 1:
                del dic[gems[start]]
            else:
                dic[gems[start]] -= 1
            start += 1

        else:
            if end < len(gems):
                if gems[end] not in dic.keys():
                    dic[gems[end]] = 1
                else:
                    dic[gems[end]] += 1     
            end += 1

    return answer