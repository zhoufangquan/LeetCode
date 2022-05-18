T = int(input())


def merge(arr, l, r):
    ans = 0
    mid = (l+r) // 2
    i, j = mid-1, r-1
    while i >= l and j >= mid:
        if arr[i] >= arr[j]:
            ans += (j-mid+1)
            i -= 1
        else:
            j -= 1

    i, j = mid-1, r-1
    temp = []
    while i >= l and j >= mid:
        if arr[i] >= arr[j]:
            temp.append(arr[i])
            i -= 1
        else:
            temp.append(arr[j])
            j -= 1
    while i >= l:
        temp.append(arr[i])
        i -= 1
    while j >= mid:
        temp.append(arr[j])
        j -= 1
    i = l
    while len(temp)>0:
        arr[i] = temp.pop()
        i += 1

    return ans


def solve(arr, l, r):  # [l, r)
    ans = 0
    if l+1 == r:
        return ans
    ans += solve(arr, l, (l+r)//2)
    ans += solve(arr, (l+r)//2, r)
    ans += merge(arr, l, r)

    return ans


while T > 0:
    n = int(input())
    arr = list(map(int, input().split()))
    print(solve(arr, 0, n))
    T -= 1
