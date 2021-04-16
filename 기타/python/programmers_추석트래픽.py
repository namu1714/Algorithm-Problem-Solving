import datetime

def stringToTimestamp(string):
    timeObj = datetime.datetime.strptime(string, "%Y-%m-%d %H:%M:%S.%f")
    return timeObj.timestamp() * 1000

def secondToMilli(strSec):
    sec = strSec.split("s")
    return int(float(sec[0]) * 1000)

def solution(lines):
    answer = 0
    times = []

    for line in lines:
        tmp = line.split(" ")
        end = stringToTimestamp(tmp[0] + " " + tmp[1])
        start = end - secondToMilli(tmp[2]) + 1
        times.append([start, end])

    for i in times:
        cnt = 0
        startTime = i[0] - 999
        endTime = i[0]

        for j in times:
            if j[0] > endTime or j[1] < startTime:
                continue
            if j[1] >= startTime or j[0] <= endTime:
                cnt += 1

        if cnt > answer:
            answer = cnt

    return answer