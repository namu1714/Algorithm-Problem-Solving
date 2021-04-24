def replaceSharp(music):
    str1 = ['C#','D#','F#','G#','A#']
    str2 = ['c', 'd', 'f', 'g', 'a']
    for i in range(0,len(str1)):
        music = music.replace(str1[i], str2[i])
    return music

def getSeconds(str):
    tmp = str.split(":")
    return int(tmp[0]) * 60 + int(tmp[1])

def solution(m, musicinfos):
    answer = ''
    m = replaceSharp(m)
    maxTime = 0
    
    for i in musicinfos:
        info = i.split(",")
        title = info[2]
        length = getSeconds(info[1]) - getSeconds(info[0])
        rawMusic = replaceSharp(info[3])
        
        music = ""
        for j in range(0, length, len(rawMusic)):
            if length - j < len(rawMusic):
                music += rawMusic[0:length-j]
            else:
                music += rawMusic
        
        if m in music and length > maxTime:
            answer = title
            maxTime = length
    
    if maxTime == 0:
        answer = "(None)"
    
    return answer