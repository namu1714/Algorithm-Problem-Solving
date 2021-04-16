def solution(files):
    answer = []
    fileList = []
    
    for title in files:
        tail = len(title)
        
        for i in range(len(title)):
            if title[i].isdigit() == True:
                number = i
                break  
                
        for i in range(number, len(title)):
            if title[i].isdigit() == False:
                tail = i
                break
                
        fileList.append([title[0:number], title[number:tail], title[tail:]])
    
    fileList.sort(key = lambda x : (x[0].lower(), int(x[1])))
    
    answer = list([''.join(f) for f in fileList])
    
    return answer