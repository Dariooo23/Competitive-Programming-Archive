#Karol Dziekan

Tests = int(raw_input())

for _ in range(Tests):
    #Wczytanie danych, stworzenie grafu i grafu odwrotnego
    data = map(int, raw_input().split())

    n = data[0]
    m = data[1]
    graph = [[] for _ in range(n)]
    transposed_graph = [[] for _ in range(n)]

    if n == 0:
        print -1
        continue

    for i in range(m):
        a = data[2 + 2 * i]
        b = data[2 + 2 * i + 1]
        graph[a].append(b)

    for u in range(n):
        for v in graph[u]:
            transposed_graph[v].append(u)



    #Sortowanie topologiczne grafu
    visited = [False] * n
    topo_order = []

    def dfs_iterative(start):
        stack = []
        stack.append((start, False))
        while stack:
            u, processed = stack.pop()
            if processed:
                topo_order.append(u)
                continue
            if not visited[u]:
                visited[u] = True
                stack.append((u, True))
                for v in graph[u]:
                    if not visited[v]:
                        stack.append((v, False))
    
    for i in range(n):
        if not visited[i]:
            dfs_iterative(i)
    
    topo_order.reverse()



    #Policzenie silnie spojnych skladowych
    scc_id = [-1] * n
    current_scc = 0

    def reverse_dfs_iterative(start):
        stack = [start]
        while stack:
            u = stack.pop()
            if scc_id[u] == -1:
                scc_id[u] = current_scc
                for v in transposed_graph[u]:
                    if scc_id[v] == -1:
                        stack.append(v)
    
    for u in topo_order:
        if scc_id[u] == -1:
            reverse_dfs_iterative(u)
            current_scc += 1



    #Sprawdzenie czy z pierwszego wierzcholka w toposort mozna dojsc do kazdego innego
    if not topo_order:
        print -1
        continue

    start = topo_order[0]

    visited = [False] * n
    def dfs_check_iterative(start):
        stack = [start]
        while stack:
            u = stack.pop()
            if not visited[u]:
                visited[u] = True
                for v in graph[u]:
                    if not visited[v]:
                        stack.append(v)

    dfs_check_iterative(start)



    #Jesli sie da to szukamy minimalnego wierzcholka w tej samej silnie spojnej skladowej
    if not all(visited):
        print -1
    else:
        scc_num = scc_id[start]
        min_vertex = min(i for i in range(n) if scc_id[i] == scc_num)
        print min_vertex



# Kod realizuje algorytm Kosaraju do znajdowania silnie spojnych skladowych (SCC) w grafie skierowanym.
# Najpierw wykonuje sortowanie topologiczne, potem DFS na grafie transponowanym, by ponumerowac SCC.
# Nastepnie sprawdza, czy z pierwszego wierzcholka w kolejnosci topologicznej mozna dojsc do wszystkich innych.
# Jesli tak, wypisuje najmniejszy numer wierzcholka z tej SCC, w przeciwnym razie wypisuje -1.

# Zlozonosc czasowa: O(n + m), poniewaz algorytm jedynie wykonuje kilka przejsc DFS, dzialajacych w zlozonosci O(n + m) kazdy,
# oraz liniowe przejscie po tablicy odwiedzonych wierzcholkow w celu znalezienia najmniejszego wierzcholka w SCC.

# Zlozonosc pamieciowa: O(n), poniewaz algorytm korzysta z kilku pomocniczych tablic, zaleznych liniowo od liczby wierzcholkow,
# czyli topo_order, visited, scc_id. Dodatkowo kilka stackow dla iteracyjnych DFS, ale ich rozmiar jest ograniczony do n.