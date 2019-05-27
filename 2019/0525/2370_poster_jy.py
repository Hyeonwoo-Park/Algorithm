#메모리 초과
#https://www.acmicpc.net/problem/2370
import sys
input = sys.stdin.readline

def solve(p,m) :
    result = 0
    l = [0]*m
    for i,j in enumerate(p) :
        l[j[0]-1:j[1]] = [i+1]*(j[1] - j[0] + 1)
        
    for i in range(len(p)) :
        if i + 1 in l :
            result += 1
            
    return result

def main():
    n = int(input())
    position = list()
    M = 0
    for _ in range(n) :
        a = list( map( int, input().split() ) )
        if M < max(a) :
            M = max(a)
        position.append(a)

    print(solve(position, M))
    
    return 0;

main()
