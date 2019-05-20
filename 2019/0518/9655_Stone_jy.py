import sys
input = sys.stdin.readline

def solve(Num):
    remain = Num % 3
    if Num//3%2 == 0:
        if remain == 0 or remain == 2:
            return "CY"
        else:
            return "SK"
    else:
        if remain == 0 or remain == 2:
            return "SK"
        else:
            return "CY"


def Main() :
    Num = int(input())
    Winner = solve(Num)
    print(Winner)
    
Main()
