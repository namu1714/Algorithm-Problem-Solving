SELECT = [['cpp', 'java', 'python'],
          ['backend', 'frontend'],
          ['junior', 'senior'],
          ['chicken', 'pizza']]


def makeDictKey(dic, arr, cnt):
    if cnt == 4:
        dic[tuple(arr)] = []
        return
    
    for s in SELECT[cnt]:
        newArr = arr[:]
        newArr.append(s)
        makeDictKey(dic, newArr, cnt + 1)
        
        
def getTotalUpperScore(score, arr):
    start, end = 0, len(arr)
    
    while start < end:
        
        mid = (start + end) // 2
        if arr[mid] <= score:
            start = mid + 1
        else:
            end = mid
            
    return len(arr) - start


def solution(info, query):
    answer = []
    dic = {}
    makeDictKey(dic, [], 0)
    
    for i in info:
        infoArr = i.split(" ")
        score = int(infoArr[4])
        dic[tuple(infoArr[:-1])].append(score)
    
    for scoreList in dic.values():
        scoreList.sort()
        
    for q in query:
        terms = q.split(" ")
        score = int(terms[7])
        terms = terms[::2] #and 제거
        
        total = 0
        
        for key, value in dic.items():
            flag = True
            for i in range(4):
                if terms[i] != '-' and terms[i] != key[i]:
                    flag = False
                    break     
            if flag == False : continue
                
            total += getTotalUpperScore(score - 1, value)
        
        answer.append(total)
    
    return answer