def find(num):
    while num in dic.keys():
        num = dic[num]
    return num

def modify(num, next_room):
    cur = num
    while cur != next_room:
        next = dic[cur]
        dic[cur] = next_room + 1
        cur = next
    
def solution(k, room_number):
    global dic
    answer = []
    dic = dict()
    
    for num in room_number:
        if num not in dic.keys():
            dic[num]  = find(num+1)
            answer.append(num)        
        else:
            next_room = find(num)
            answer.append(next_room)
            modify(num, next_room)
            dic[next_room] = next_room + 1
    
    return answer