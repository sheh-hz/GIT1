lst=['abc', 'xyz', 'aba', '1221']
c=0
for i in lst:
    if len(i)>=2 and i[0]==i[-1]:
        c+=1
        print(i)
print(c)