list1 = [1, 2, 3, 4]
list2 = [3, 4, 5, 6]
common = []
for i in list1:
    if i in list2:
        common.append(i)

print(common)


lst = [[1, 2], [3, 4], [5, 6]]
flat = []
for sublist in lst:
    for item in sublist:
        flat.append(item)

print(flat)

squares = [x**2 for x in range(1, 11)]
print(squares)