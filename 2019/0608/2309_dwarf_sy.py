import itertools

dwarfs = list()

for _ in range(9):
    dwarfs.append(int(input()))

com = list(itertools.combinations(dwarfs, 7))

for dwarf in com:
    if sum(dwarf) == 100:
        result = list(dwarf)
        break

result.sort()
for i in result:
    print(i)