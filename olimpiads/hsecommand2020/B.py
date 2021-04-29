a = []
N = int(input())
answ = []

for i in range(N):
    answ.append([0, 0])
    l, r = map(int, input().split())
    a.append([l,r,i])

a.sort(key=lambda x: x[0])
crr = a[0]

for i in range(1, N):
    if (crr[1] >= a[i][1]):
        answ[a[i][2]] = [-1, -1]
    else:
        answ[crr[2]][0] = crr[0]
        answ[crr[2]][1] = min(crr[1], a[i][0])
        crr = a[i]

answ[crr[2]] = crr
for i in range(N):
    print(answ[i][0], answ[i][1])
