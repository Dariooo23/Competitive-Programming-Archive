def solve():
    n = int(input())

    arr = list(input())
    
    count_ = 0
    count__ = 0

    for i in range(n):
        if arr[i] == '-':
            count_ += 1
        else:
            count__ += 1

    print((count_ // 2) * ((count_ - 1) // 2 + 1) * count__)


cases = int(input())

while cases > 0:
    solve()
    cases -= 1
