'''
l=[]
for i in range(5):
    d=input()
    l.append(d)
print(l)
l=tuple(l)
print(l)


my_tuple = (10, 20, 30, 40, 50)
print(my_tuple[0])
print(my_tuple[-1])


tu=(1,2,3)
a,b,c=tu
print(a,b,c)


my_tuple = ('a', 'b', 'c')
if 'b' in my_tuple:
    print(True)
else:
    print(False)


t = (0, 1, 2, 3, 4, 5)
o=t[1:4]
print(o)


t = (10, 20, 30, 40)
print(len(t))


t = ("apple", "banana", "cherry")
for i in t:
    print(i)


t1 = (1, 2)
t2 = (3, 4)
t3=t1+t2
print(t3)


t = (5, 6)
t=t*3
print(t)

'''
t = (11, 3, 55, 21)
print(max(t))
print(min(t))