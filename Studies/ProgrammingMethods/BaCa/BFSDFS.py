from collections import deque

class Node:
    def __init__(self, numer):
        self.numer = numer
        self.dzieci = []


def wczytanie_grafu():
    n = int(input())
    m = int(input())
    
    wezly = [Node(i) for i in range(n)]

    for _ in range(m):
        a, b = map(int, input().split())
        wezly[a].dzieci.append(wezly[b])
        wezly[b].dzieci.append(wezly[a])
    return wezly

def bfs(wezly, start):
    odwiedzone = [False] * len(wezly)

    kolejka = deque([start])
    odwiedzone[start.numer] = True

    while kolejka:
        node = kolejka.popleft()
        print(node.numer, " ")

        for dziecko in node.dzieci:
            if not odwiedzone[dziecko.numer]:
                odwiedzone[dziecko.numer] = True
                kolejka.append(dziecko)
    
    print()


def dfs(wezly, start):
    odwiedzone = [False] * len(wezly)

    def dfs_helper(node):
        odwiedzone[node.numer] = True
        print(node.numer, " ")

        for dziecko in node.dzieci:
            if not odwiedzone[dziecko.numer]:
                dfs_helper(dziecko)

    dfs_helper(start)

    print()



wezly = wczytanie_grafu()
start = int(input())
print()

bfs(wezly, wezly[start])
dfs(wezly, wezly[start])