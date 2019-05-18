import sys
input = sys.stdin.readline

def check_rectangle(Line) :
    area = 0
    for i in range(len(Line)) :
        for j in range(len(Line) - i) :
            area = max(area, ((i + 1) * min(Line[j:j+i+1])) )
    return area

    
def Main() :
    Result = []
    while True :
        Line = list( map( int, input().split() ) )
        
        Num = Line[0]
        del Line[0]
        
        if Num == 0 : break

        temp_result = check_rectangle(Line)
        
        Result.append(temp_result)

    for i in Result :
        print(i)
        
Main()
