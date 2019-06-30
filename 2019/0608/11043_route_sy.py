n = int(input())
lines = []
for _ in range(n):
    line = list(map(int, input().split()))
    lines.append(line)



for k in range(n):
    for i in range(n):
        for j in range(n):
            if lines[i][k] and lines[k][j]:
                lines[i][j] = 1

for i in range(n):
    line = " ".join(list(map(str, lines[i])))
    print(line)