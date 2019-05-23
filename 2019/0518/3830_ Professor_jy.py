
#Time over T.T

import sys
input = sys.stdin.readline

connect = dict()

def bfs(graph, start_node):
   global connect
   visit = dict()
   queue = list()

   queue.append([start_node, start_node, 0])
   
   while queue:
      node = queue.pop(0)
      if node[1] not in visit.keys():
         if node[0] in visit.keys() :
            cost = visit[node[0]] + node[2]
            visit[node[1]] = cost
            connect[node[1]][start_node] = -cost
         else :
            visit[node[1]] = node[2]
         for i in list( map( list ,graph[node[1]].items() ) ) :
            queue.append( [node[1]] + i  )
   return visit


def check(mydict,start, end) :
   global connect
   result = False
   money = 0
   connect[start] = dict(bfs(mydict, start))
   if end in connect[start] :
      money = connect[start][end]
      result = True
   return money, result

def main() :
   global connect
   while True :
      kinds, Num = tuple(map(int, input().split()))      
      if kinds == Num and kinds == 0 : break
      
      index = 0
      kinds_list = [ 0 for i in range(kinds)]
      base_index = [ -1 for i in range(kinds)]
      connect.clear()
         
      for _ in range(Num) :
         q = input().split()
         mark = q[0]
         q = list(map(int, q[1:]))
         q[0], q[1] = q[0] - 1, q[1] - 1
         
         if mark == "?" :
            if base_index[q[0]] != -1 and base_index[q[1]] != -1 and base_index[q[1]] == base_index[q[0]]:
               print(kinds_list[q[1]] - kinds_list[q[0]])
            else :
               if base_index[q[0]] == -1 or base_index[q[1]] == -1 :
                  print("UNKNOWN")
               else :
                  if base_index[q[1]] in connect[base_index[q[0]]] :
                     print(kinds_list[q[1]] - kinds_list[q[0]] + connect[base_index[q[0]]][base_index[q[1]]])
                  elif base_index[q[0]] in connect[base_index[q[1]]] :
                     print(kinds_list[q[1]] - kinds_list[q[0]] - connect[base_index[q[0]]][base_index[q[1]]])
                  else :
                     money, cango = check(connect , base_index[q[0]] ,  base_index[q[1]]  )
                     if cango == True:
                        print(kinds_list[q[1]] - kinds_list[q[0]] + money)
                     else :
                        print("UNKNOWN")
         else :
            if q[0] > q[1] :
               q[0],q[1],q[2] = q[1],q[0],-q[2]
               
            if base_index[q[0]] == base_index[q[1]] :
               if base_index[q[0]] == -1 :
                  if index not in connect.keys() :
                     connect[index] = {}
                  base_index[q[1]],base_index[q[0]] = index,index
                  index = index + 1
                  kinds_list[q[1]] = kinds_list[q[0]] + q[2]
                  
            elif base_index[q[0]] != base_index[q[1]] :
               if base_index[q[0]] == -1 :
                  base_index[q[0]] = base_index[q[1]]
                  kinds_list[q[0]] = kinds_list[q[1]] + q[2]
               elif base_index[q[1]] == -1 :
                  base_index[q[1]] = base_index[q[0]]
                  kinds_list[q[1]] = kinds_list[q[0]] + q[2]
               else :
                  if base_index[q[1]] not in connect[base_index[q[0]]] :
                     c = kinds_list[q[0]] + q[2]
                     connect[base_index[q[0]]][base_index[q[1]]] = c
                     connect[base_index[q[1]]][base_index[q[0]]] = - c


main()
