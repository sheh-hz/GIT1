
t1 = (1, 2, 3, 4)
t2 = (3, 5, 2, 1)
t3 = (2, 2, 3, 1)
t4=[]
for i,j,k in zip(t1,t2,t3):
    sum=i+j+k
    t4.append(sum)
t4=tuple(t4)
print(t4)


t = (4, 3, 2, 2, -1, 18)
mul=1
for i in t:
    mul*=i
print(mul)


t = (1, 2, 3)
a=""
for i in t:
    a+=str(i)
print(a)


t = (('item1', '12.20'), ('item2', '15.10'), ('item3', '24.5'))
result = sorted(t, key=lambda x: x[1],reverse=True)
print(result)


t1 = (1, 2)
t2 = (3, 4)
result = []
for i in t1:
    for j in t2:
        result.append((i, j))
print(result)


t = (1, 2, 2, 3, 3, 3)
freq = {}
for i in t:
    if i in freq:
        freq[i] += 1
    else:
        freq[i] = 1
print(freq)



lst = [(1, 2, 3), (4, 5), (6, 7, 8)]
result = []
for i in lst:
    if len(i) == 3:
        result.append(i)

print(result)
