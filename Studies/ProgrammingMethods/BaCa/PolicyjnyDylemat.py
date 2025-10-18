#Karol Dziekan

INF = 10**18

L = int(raw_input())

for _ in range(L):
    parts = map(int, raw_input().split())
    n = parts[0]
    k = parts[1]
    m = parts[2]
    edge_data = parts[3:]

    edges = []
    for i in range(m):
        a = edge_data[3 * i]
        b = edge_data[3 * i + 1]
        c = edge_data[3 * i + 2]
        edges.append((a, b, c))

    prev_cost = [INF] * n
    prev_cost[0] = 0

    best = INF

    for step in range(0, k + 1):
        curr_cost = [INF] * n
        for i in range(len(edges)):
            u, v, c = edges[i]
            if prev_cost[u] < INF:
                cost = prev_cost[u] + c
                if cost < curr_cost[v]:
                    curr_cost[v] = cost
        if curr_cost[n - 1] < best:
            best = curr_cost[n - 1]
        prev_cost = curr_cost

    if best == INF:
        print -1
    else:
        print best