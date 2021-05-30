def solution(record):
    answer = []
    uidList = dict()    

    for rec in record:
        cmd = rec.split(" ")
        if cmd[0] == "Enter" or cmd[0] == "Change":
            uidList[cmd[1]] = cmd[2]

    for rec in record:
        cmd = rec.split(" ")
        str = uidList[cmd[1]]
        if cmd[0] == "Enter":
            str += "님이 들어왔습니다."
            answer.append(str)
        elif cmd[0] == "Leave":
            str += "님이 나갔습니다."
            answer.append(str)    

    return answer