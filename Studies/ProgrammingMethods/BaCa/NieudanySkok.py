#Karol Dziekan
def input():
    return raw_input()

def median_of_medians(arr, left, right):
    n = right - left + 1
    if n <= 5:
        for i in range(left, right + 1):
            for j in range(i + 1, right + 1):
                if arr[j] < arr[i]:
                    arr[i], arr[j] = arr[j], arr[i]
        return arr[left + n // 2]
    
    medians_left = left
    i = left

    while i <= right:
        sub_right = min(i + 4, right)

        for x in range(i, sub_right + 1):
            for y in range(x + 1, sub_right + 1):
                if arr[y] < arr[x]:
                    arr[x], arr[y] = arr[y], arr[x]

        median_index = i + (sub_right - i) // 2
        arr[medians_left], arr[median_index] = arr[median_index], arr[medians_left]

        medians_left += 1
        i += 5

    median_idx = left + (medians_left - left) // 2
    return select_kth(arr, left, medians_left - 1, median_idx)



def partition(arr, left, right, pivot_value):
    low = left
    mid = left
    high = right

    while mid <= high:
        if arr[mid] < pivot_value:
            arr[low], arr[mid] = arr[mid], arr[low]
            low += 1
            mid += 1

        elif arr[mid] > pivot_value:
            arr[mid], arr[high] = arr[high], arr[mid]
            high -= 1

        else:
            mid += 1

    return low, high



def select_kth(arr, left, right, k):
    if left == right:
        return arr[left]
    
    pivot_value = median_of_medians(arr, left, right)
    low, high = partition(arr, left, right, pivot_value)

    if k < low:
        return select_kth(arr, left, low - 1, k)
    
    elif k > high:
        return select_kth(arr, high + 1, right, k)
    
    else:
        return pivot_value



z = int(input())
while z > 0:
    n = int(input())
    arr = map(int, input().split())

    m = int(input())
    queries = map(int, input().split())

    for k in queries:
        k_idx = k - 1

        if k_idx < 0 or k_idx >= n:
            print(str(k) + " brak")

        else:
            res = select_kth(arr, 0, n - 1, k_idx)
            print(str(k) + " " + str(res))

    z -= 1