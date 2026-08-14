'''
lst = [1, 2, 3]
tup = (4, 5, 6)
lst=tuple(lst)
tup=list(tup)
print(lst)
print(tup)


t = (1, 2, 3)
t=list(t)
t.append(4)
t=tuple(t)
print(t)


t = (1,2,3,4)
t=list(t)
t.remove(2)
t=tuple(t)
print(t)


t = ('P', 'y', 't', 'h', 'o', 'n')
str=""
Tuple=[]
for i in t:
    str+=i
print(str)
for i in str:
    Tuple+=i
Tuple=tuple(Tuple)
print(Tuple)


t = (("11", "22"), ("33", "44"))
result=()
for inner in t:
    temp=()
    for num in inner:
        temp = temp + (int(num),)
    result = result + (temp,)

print(result)


t = ("cat", "dog", "rabbit")
for i in t:
    if i=="dog":
        print(t.index(i))
        break
        

t = (1, 2, 3, 2, 2, 4)
print(t.count(2))


t = (10, 20, 30, 40)
t=list(t)
t.reverse()
t=tuple(t)
print(t)



t = (2, 4, 6, 2, 8, 4, 6, 2)
for i in range(len(t)):
    count = 0
    for j in range(len(t)):
        if t[i] == t[j]:
            count += 1
    if count > 1:
        duplicate = False
        for k in range(i):
            if t[i] == t[k]:
                duplicate = True
                break
        if not duplicate:
            print(t[i])



t = (1, 2, 3, 4, 5)

if len(t) == len(set(t)):
    print("All elements are unique")
else:
    print("Duplicate elements found")

'''