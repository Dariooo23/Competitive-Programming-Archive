
def solve():
    n = int(input())
    arr = list(map(int, input().split()))


    odd_number = 0
    sum = 0
    for i in range(n):
        sum += arr[i]
        if arr[i] % 2 == 1:
            odd_number += 1

    if odd_number == 0 or odd_number == n:
        print(max(arr))
    else:
        print (sum - odd_number + 1)


cases = int(input())

while cases > 0:
    solve()
    cases -= 1