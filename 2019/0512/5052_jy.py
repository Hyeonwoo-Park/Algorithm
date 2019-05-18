import sys
input = sys.stdin.readline

def solution(phone_book):
    phone_book.sort()
    answer = "YES"
    for i in range(0,len(phone_book) - 1):
        if phone_book[i] == phone_book[i+1][:len(phone_book[i])]:            
            answer = "NO"
            return answer
    return answer

def Main() :
    TestNum = int(input())
    Addr_list = [ [] for i in range(0,TestNum) ]

    for i in range(0,TestNum) :
        n = int(input())
        for j in range(0,n) :
            addr = input()
            Addr_list[i].append(addr[:-1])
            
    for i in range(0,TestNum) :
        print(solution(Addr_list[i]))

Main()
