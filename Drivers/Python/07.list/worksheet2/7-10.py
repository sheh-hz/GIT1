lst = [1, 2, 3, 2, 4, 3, 5]
result = []

for i in lst:
    if i not in result:
        result.append(i)

print(result)

lst = []
if len(lst) == 0:
    print("List is empty")
else:
    print("List is not empty")


lst = [1, 2, 3, 4]
copy_lst = lst.copy()
print(copy_lst)


words = ["apple", "cat", "banana", "dog", "elephant"]
n = 5
result = []
for word in words:
    if len(word) > n:
        result.append(word)

print(result)

