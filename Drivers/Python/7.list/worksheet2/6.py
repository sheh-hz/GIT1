n = int(input("Enter the number of tuples: "))

lst = []

for i in range(n):
    a = int(input("Enter first element: "))
    b = int(input("Enter second element: "))
    lst.append((a, b))

print("Original List:", lst)

# Sort by the second element of each tuple
sorted_list = sorted(lst, key=lambda x: x[1])

print("Sorted List:", sorted_list)