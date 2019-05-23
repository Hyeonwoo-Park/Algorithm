import sys
input = sys.stdin.readline

def Find(List) :
    length = len(List)
    dp = [ [ 0, 0 ,0 ] for i in range(length) ]
    dp[0] = List[0]
    for i in range(1, length) :
        R,G,B = List[i][0], List[i][1], List[i][2]
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + R
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + G
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + B
    cost = min(dp[-1])
    return cost

def main() :
    N = int(input())
    Num_List = []
    Money = 0
    for _ in range(N) :
        Num_List.append(list( map( int, input().split())))

    Cost = Find(Num_List)
    print(Cost)

main()
