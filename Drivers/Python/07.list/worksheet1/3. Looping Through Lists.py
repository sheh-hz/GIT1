lst=[1,2,3,4,5]
for i in lst:
    print(i)
i=0
while(i<len(lst)):
    print(lst[i])
    i+=1
nnewl=[x**2 for x in lst]
print(nnewl)