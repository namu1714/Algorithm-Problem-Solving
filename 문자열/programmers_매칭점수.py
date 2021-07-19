def getWordCount(word, str):
    cnt = 0
    start, end = 0, 0

    for end in range(len(str)):
        if str[end].isalpha() == False:
            if str[start:end] == word:
                cnt += 1
            start = end + 1
    return cnt

def solution(word, pages):
    answer = 0
    dic = {} #page index 저장
    pageList = [] #page 정보 저장
    index = 0

    for page in pages:
        url = page.split('head>')[1].split('<meta')[2].split('\"')[3]
        body = page.split('body>')[1].rstrip('</').lower()
        baseScore = getWordCount(word.lower(), body)

        links = []
        for a in body.split('<a '):
            if a.startswith('href'):
                links.append(a.split('<\a>')[0].split('\"')[1])

        dic[url] = index
        pageList.append([baseScore, len(links), links, baseScore])
        index += 1

    for url in dic.keys():
        linkScore = 0
        pageInfo = pageList[dic[url]]
        if pageInfo[1] != 0:
            linkScore = pageInfo[0] / pageInfo[1]
        links = pageInfo[2]

        for link in links:
            if link in dic.keys():
                pageList[dic[link]][3] += linkScore

    maxScore = 0
    for i in range(len(pageList)):
        if pageList[i][3] > maxScore:
            maxScore = pageList[i][3]
            answer = i

    return answer