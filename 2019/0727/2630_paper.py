n = int(input())

matrix = []
for _ in range(n):
    row = list(map(int,input().split()))
    matrix.append(row)

blueCnt = 0
whiteCnt = 0

def divide(myList):
    oneCnt = 0
    zeroCnt = 0
    size = len(myList)**2
    global blueCnt
    global whiteCnt
    
    for array in myList:
        
        oneCnt+=array.count(1)
        zeroCnt+=array.count(0)

    if oneCnt == size:
        blueCnt+=1
        return
    elif zeroCnt == size:
        whiteCnt+=1
        return
    else:
        mid = len(myList)//2
        leftTopMatrix = [array[:mid] for array in myList[:mid]]
        rightTopMatrix = [array[mid:] for array in myList[:mid]]
        leftBottomMatrix = [array[:mid] for array in myList[mid:]]
        rightBottomMatrix = [array[mid:] for array in myList[mid:]]

        divide(leftTopMatrix)
        divide(rightTopMatrix)
        divide(leftBottomMatrix)
        divide(rightBottomMatrix)
        return
divide(matrix)

print(whiteCnt)
print(blueCnt)
