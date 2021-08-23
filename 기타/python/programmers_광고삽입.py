def getSeconds(time_str):
    times = list(map(int, time_str.split(":")))
    return times[0] * 60 * 60 + times[1] * 60 + times[2]

def getTimeString(seconds):
    return "%02d:%02d:%02d" % (seconds//3600, seconds%3600//60, seconds%60)

def solution(play_time, adv_time, logs):
    arr = [0] * 360000
    play_time = getSeconds(play_time)
    adv_time = getSeconds(adv_time)
    
    for log in logs:
        tmp = log.split("-")
        arr[getSeconds(tmp[0])] += 1
        arr[getSeconds(tmp[1])] -= 1
        
    for i in range(1, play_time + 1):
        arr[i] = arr[i-1] + arr[i]
            
    total_time = 0
    start, end = 0, adv_time
    
    for i in range(start, end):
        total_time += arr[i]
        
    best_time, best_start = total_time, 0
    
    while True:
        start +=1; end += 1
        if end > play_time: break
        
        total_time -= arr[start - 1]
        total_time += arr[end - 1]
        
        if total_time > best_time:
            best_time = total_time
            best_start = start
        
    answer = getTimeString(best_start)
                        
    return answer