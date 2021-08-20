import re

def solution(new_id):
    answer = ''
    
    new_id = new_id.lower() #1
    new_id = re.sub('[^a-z0-9-_.]', "", new_id) #2
    new_id = re.sub('\.+', ".", new_id) #3
    
    #4
    if new_id.startswith('.') and len(new_id) > 1:
        new_id = new_id[1:]
    if new_id.endswith('.'):
        new_id = new_id[:-1]
        
    #5
    if new_id == "":
        new_id = "a"
        
    #6
    new_id = new_id[:15]
    if new_id.endswith('.'):
        new_id = new_id[:-1]
    
    #7
    while len(new_id) < 3:
        new_id += new_id[-1]

    answer = new_id
    
    return answer