n = int(input())

num = []
for _ in range(n):
    num.append(int(input()))

num.sort()
num.reverse()

result = 0
for i in range(1, n + 1):
    temp = num[i - 1] * i
    if result < temp:
        result = temp

print(result)