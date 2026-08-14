llst = [("Alice", 25), ("Bob", 20), ("Eve", 22)]
result = sorted(llst, key=lambda x: x[1])
print(result)

lst = [(1, 2), (10, 11), (3, 44)]
result = sorted(lst, key=lambda x: x[0])
print(result)

t = ((1, 2), (3, 4), (5, 6))
result = ()
for i in t:
    for j in i:
        result = result + (j,)
print(result)

t = ((1, 2), (2, 3), (4, 5))
result = set()
for i in t:
    result.update(i)
print(result)