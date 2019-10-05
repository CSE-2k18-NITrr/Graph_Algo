def dfs(src, visited):
    stack = []
    stack.append(src)
    cnt = 0
    while stack:
        curr = stack.pop()
        if curr in graph:
            for node in graph[curr]:
                if node not in visited:
                    stack.append(node)
                    cnt+=1
                    visited[node] = 1
    return cnt, visited

t = int(input())
while t:
    n, m, clib, croad = [int(x) for x in input().strip().split()]
    graph = {}
    for i in range(m):
        u, v = [int(x) for x in input().strip().split()]
        if u not in graph:
            graph[u] = []
        if v not in graph:
            graph[v] = []
        graph[u].append(v)
        graph[v].append(u)

    cost = 0
    visited = {}
    for i in range(1,n+1):
        if i not in visited:
            cnt, visited = dfs(i, visited)
            if cnt==0:
                cost+=clib
            elif clib<croad:
                cost+=clib*cnt
            else:
                cost+=clib+(cnt-1)*croad
    print(cost)
    t-=1
    
