#https://www.acmicpc.net/problem/1124
import sys
input = sys.stdin.readline

def prime_list(n):
    sieve = [0] * n
    sieve[0],sieve[1] = 1,1

    for i in range(2, n):
        if sieve[i] == 0:
            for j in range(i+i, n, i):
                nn = j
                while nn % i == 0 :
                    nn //= i
                    sieve[j] += 1

    return sieve

def main() :
    pl = prime_list(100001)
    cnt = 0
    A,B = map(int, input().split())
    for i in range(A,B+1) :
        if (pl[pl[i]] == 0) :
            cnt += 1
            
    print(cnt)
    
    return 0;
        
main()
