#https://www.acmicpc.net/problem/2370
import sys
input = sys.stdin.readline

def main():
    N = int(input())
    f = (lambda x,y: x if x > y else y)
    rope = list()
    max = 0
    for i in range(N) :
        rope.append(int(input()))
    rope.sort(reverse = True)
    for i in range(N) :
        max = f(max,rope[i]*(i+1))
    
    print(max)
    
    return 0;

main()
