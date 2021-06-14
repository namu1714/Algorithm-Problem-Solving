from itertools import combinations

def solution(relation):
    answer = 0
    items = list(i for i in range(len(relation[0])))
    candidate = []
    
    for k in range(1, len(items) + 1) :
        for comb in list(combinations(items, k)):
            unique, minimal = True, True
            
            for c in candidate:
                if set(c) - set(comb) == set():
                    minimal = False
                    break
            if minimal == False: continue
                    
            keyList = list()
            for r in relation:
                keyTuple = tuple(r[i] for i in comb)
                if keyTuple in keyList: 
                    unique = False
                    break
                keyList.append(keyTuple)
                
            if unique == True:    
                answer += 1
                candidate.append(comb)                

    return answer