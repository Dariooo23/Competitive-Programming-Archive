
def solve():
    n = int(input())
    arr1 = list(input())
    arr2 = list(input())

    count1 = 0
    count2 = 0

    for i in range(n):
        if i % 2 == 0:
            if arr1[i] == '1':
                count1 += 1
        else:
            if arr1[i] == '1':
                count2 += 1

    for i in range(n):
        if i % 2 == 1:
            if arr2[i] == '1':
                count1 += 1
        else:
            if arr2[i] == '1':
                count2 += 1

    if (count1 > (n // 2)) or (count2 > ((n - 1) // 2 + 1)):
        print("NO")
    else:
        print("YES")

cases = int(input())

while cases > 0:
    solve()
    cases -= 1