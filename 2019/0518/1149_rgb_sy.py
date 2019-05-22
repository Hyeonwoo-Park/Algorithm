n = int(input())
rgb = []
cost = [[0 for _ in range(3)] for _ in range(n)]
for _ in range(n):
    rgb.append(list(map(int, input().split())))

for i in range(n):
    cost[i][0] = min([cost[i-1][1], cost[i-1][2]]) + rgb[i][0]
    cost[i][1] = min([cost[i-1][0], cost[i-1][2]]) + rgb[i][1]
    cost[i][2] = min([cost[i-1][1], cost[i-1][0]]) + rgb[i][2]

print(min(cost[n-1]))


# 3
# 26 40 83
# 49 60 57
# 13 89 99