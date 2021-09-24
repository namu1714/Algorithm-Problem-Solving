def distribute(name, profit, sales, sellers):
    recommender = sellers[name]
    distribution = int(profit * 0.1)
    sales[name] += profit-distribution
    
    if recommender != "-" and distribution > 0:
        distribute(recommender, distribution, sales, sellers)

def solution(enroll, referral, seller, amount):
    answer = []
    sales = dict()
    sellers = dict()
    
    for i in range(len(enroll)):
        sales[enroll[i]] = 0
        sellers[enroll[i]] = referral[i]
    
    for i in range(len(seller)):
        distribute(seller[i], amount[i] * 100, sales, sellers)
    
    for name in enroll:
        answer.append(sales[name])
    
    return answer