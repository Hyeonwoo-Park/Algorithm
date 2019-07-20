from collections import deque

N, M, V = map(int, input().split())
matrix = [[0] * (N + 1) for _ in range(N + 1)]
for _ in range(M):
    link = list(map(int, input().split()))
    matrix[link[0]][link[1]] = 1
    matrix[link[1]][link[0]] = 1


def dfs(current_node, foot_prints):
    foot_prints += [current_node]
    for search_node in range(N+1):
        if matrix[current_node][search_node] and search_node not in foot_prints:
            foot_prints = dfs(search_node, foot_prints)
    return foot_prints



def bfs(start):
    queue = deque()
    queue.append(start)
    foot_prints = [start]
    while queue:
        current_node = queue.popleft()
        for search_node in range(N+1):
            if matrix[current_node][search_node] and search_node not in foot_prints:
                foot_prints += [search_node]
                queue += [search_node]
    return foot_prints


print(*dfs(V, []))
print(*bfs(V))

# 4 5 1
# 1 2
# 1 3
# 1 4
# 2 4
# 3 4
