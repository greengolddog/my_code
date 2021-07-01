def selection_sort(a):
    for i in range(len(a) - 1):
        imin = i
        for j in range(i + 1, len(a)):
            if a[j] > a[imin]:
                imin = j
        a[i], a[imin] = a[imin], a[i]
inp = list(map(int, input().split()))
n = inp[0]
k = inp[1]
arr = list(map(int, input().split())) 
selection_sort(arr)
print(arr[k])