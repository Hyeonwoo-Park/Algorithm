#https://www.acmicpc.net/problem/2370
import sys
input = sys.stdin.readline

def search(rou, res, index) :
    queue = list()
    visit = list()
    queue.extend(rou[index])

    while queue :
        nxt = queue.pop(0)
        if nxt not in visit :
            visit.append(nxt)
            queue.extend(rou[nxt])
            res[index-1][nxt-1] = 1
    

def main():
    N = int(input())
    route = dict()
    result = [[0 for _ in range(N)] for _ in range(N)]
    for i in range(N) :
        route[i+1] = []
        a = list(map(int, input().split()))
        for j in range(len(a)) :
            if a[j] == 1 :
                route[i+1].append(j+1)

    for i in range(N) :
        search(route,result,i+1)
        
    for i in result :
        for j in i :
            print(j,end = " ")
        print()
    
    return 0;

main()
