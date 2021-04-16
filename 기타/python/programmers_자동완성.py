def compareStr(s, s2):
    length = (len(s) if len(s) < len(s2) else len(s2))
    
    ret = length
    if len(s) > len(s2):
        ret += 1
    
    for i in range(length):
        if s[i] != s2[i]:
            ret = i+1
            break
            
    return ret

def solution(words):
    answer = 0
    
    words.sort()
    
    for i in range(0, len(words)):
        max = 0
        if i > 0:
            tmp = compareStr(words[i], words[i-1])
            if tmp > max: max = tmp
        if i < len(words) - 1:
            tmp = compareStr(words[i], words[i+1])
            if tmp > max: max = tmp
                
        answer += max
    
    return answer