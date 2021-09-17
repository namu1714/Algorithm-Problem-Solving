import requests
import json

BASE_URL = "https://kox947ka1a.execute-api.ap-northeast-2.amazonaws.com/prod/users"


def simulate(commands, auth_key):
    header = { 'Authorization': auth_key, 'Content-Type': 'application/json' }
    response = requests.put(BASE_URL + "/simulate", headers=header, data=json.dumps({ "commands" : commands }))
    response = response.json()
    return response['status']

def getLocations(auth_key):
    header = { 'Authorization': auth_key, 'Content-Type': 'application/json' }
    response = requests.get(BASE_URL + "/locations", headers=header)
    response = response.json()
    return response['locations']

def getTrucks(auth_key):
    header = { 'Authorization': auth_key, 'Content-Type': 'application/json' }
    response = requests.get(BASE_URL + "/trucks", headers=header)
    response = response.json()
    return response['trucks']
    
def getScore(auth_key):
    header = { 'Authorization': auth_key, 'Content-Type': 'application/json' }
    response = requests.get(BASE_URL + "/score", headers=header)
    response = response.json()
    return response['score']

def start(pnum):
    header = { 'X-Auth-Token': "c61d5e8f8611c80ef40f2dc105489318", 'Content-Type': 'application/json' }
    response = requests.post(BASE_URL + "/start", headers=header, data=json.dumps({ "problem" : pnum }))
    response = response.json()
    return response['auth_key']

def initialize_map(N, mp):
    id_map = []
    idx = 0
    for i in range(N):
        for j in range(N-1, -1, -1):
            mp[j][i] = idx
            idx += 1
            id_map.append((j, i))
            
    return id_map


def problem1():
    N = 5
    auth_key = start(1)

    mp = [[0 for _ in range(N)] for _ in range(N)]
    id_map = initialize_map(N, mp)

    avg = 4

    while True:
        bikes = getLocations(auth_key)
        trucks = getTrucks(auth_key)
        commands = []

        
        
        status = simulate(commands, auth_key)
        if status == 'finished':
            break
        
    print(getScore(auth_key))
        

def problem2():
    N = 60
    auth_key = start(2)
    
    mp = [[0 for _ in range(N)] for _ in range(N)]
    id_map = initialize_map(N, mp)

    avg = 3

    while True:
        bikes = getLocations(auth_key)
        trucks = getTrucks(auth_key)
        commands = []
        
        status = simulate(commands, auth_key)
        if status == 'finished':
            break

if __name__ == '__main__':
    problem1()
    problem2()
