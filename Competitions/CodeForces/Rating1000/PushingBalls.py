
def solve():
    n, m = map(int, input().split())

    arr = [[0] * m for _ in range(n)]
    vis = [[0] * m for _ in range(n)]
    
    for i in range(n):
        arr[i] = list(input())
    
    for i in range(n):
        for j in range(m):
            if arr[i][j] == '0':
                break
            vis[i][j] = 1

    for j in range(m):
        for i in range(n):
            if arr[i][j] == '0':
                break
            vis[i][j] = 1
    
    for i in range(n):
        for j in range(m):
            if arr[i][j] == '1' and vis[i][j] == 0:
                print("NO")
                return
    
    print("YES")



cases = int(input())

while cases > 0:
    solve()
    cases -= 1