import sys

def dfs(v) :
    if v == n+1:
        sum = 0
        for i in range(1, n+1):
            if ch[i] == 1:
                sum += input[i-1]
        if 0 != sum:
            result.append(sum)            
    else :
        ch[v]=1
        dfs(v+1)
        ch[v]=0
        dfs(v+1)     

def solution(input) :
    totalSum = 0
    for element in input:
        totalSum += element

    dfs(1)
    
    min = sys.maxint

    for i in range (0, len(result)):
        diff = result[i]-(totalSum - result[i])
        if (min > diff) and (0 < diff):
            min = diff
    
    return min

if __name__ == "__main__":
    input = [3,5,7,10]
    result = []
    n = len(input)
    ch = [0] * (n+1)
    print(solution(input))