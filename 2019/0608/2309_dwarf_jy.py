#https://www.acmicpc.net/problem/2309
import sys
input = sys.stdin.readline

import itertools


def main() :
   dwarfs = list()

   for _ in range(9):
       dwarfs.append(int(input()))
       
   dwarfs = list(itertools.combinations(dwarfs,7))

   for s in dwarfs :
      if sum(s) == 100 :
         s = list(s)
         s.sort()
         break
      
   for i in s :
      print(i)
   
main()
