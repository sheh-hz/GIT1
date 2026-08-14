from itertools import permutations

numbers = [1,2,3,4,5,6,7,8,9,10]
even_numbers = [x for x in numbers if x % 2 == 0]
print(even_numbers)

lst = [1,2,3,2,4,2,5]
element = 2
result = [x for x in lst if x != element]
print(result)

lst = [1,2,3,4]
element = 5
position = 2
lst.insert(position, element)
print(lst)

keys = ['a','b','c']
values = [1,2,3]
dictionary = dict(zip(keys, values))
print(dictionary)

lst = [(1,'a'),(2,'b'),(3,'c')]
nums, chars = zip(*lst)
print(list(nums), list(chars))

result = [x**2 if x % 2 == 0 else x**3 for x in range(1,21)]
print(result)

matrix = [[i for j in range(3)] for i in range(3)]
print(matrix)

def reverse_at_position(lst, pos):
    return lst[:pos] + lst[pos:][::-1]

print(reverse_at_position([1,2,3,4,5,6],3))

def lis_length(arr):
    n = len(arr)
    dp = [1] * n
    for i in range(n):
        for j in range(i):
            if arr[i] > arr[j]:
                dp[i] = max(dp[i], dp[j] + 1)
    return max(dp)

arr = [10,22,9,33,21,50,41,60,80]
print(lis_length(arr))

arr = [1,2,3]
print(list(permutations(arr)))

def kth_smallest(lst, k):
    lst = sorted(lst)
    return lst[k-1]

print(kth_smallest([7,10,4,3,20,15],3))

def is_palindrome(lst):
    return lst == lst[::-1]

print(is_palindrome([1,2,3,2,1]))

list1 = [1,2,3,4]
list2 = [3,4,5,6]
union = list(set(list1) | set(list2))
intersection = list(set(list1) & set(list2))
print("Union:", union)
print("Intersection:", intersection)

def remove_duplicates(lst):
    result = []
    for i in lst:
        if i not in result:
            result.append(i)
    return result

print(remove_duplicates([1,2,2,3,4,4,5,6,5]))

def max_sum_subsequence(lst):
    return sum(x for x in lst if x > 0)

print(max_sum_subsequence([2,-1,2,3,4,-5]))

def longest_common_subsequence(X, Y):
    m = len(X)
    n = len(Y)
    dp = [[[] for _ in range(n+1)] for _ in range(m+1)]
    for i in range(m):
        for j in range(n):
            if X[i] == Y[j]:
                dp[i+1][j+1] = dp[i][j] + [X[i]]
            else:
                if len(dp[i][j+1]) > len(dp[i+1][j]):
                    dp[i+1][j+1] = dp[i][j+1]
                else:
                    dp[i+1][j+1] = dp[i+1][j]
    return dp[m][n]

list1 = [1,3,4,1,2,3,4,1]
list2 = [3,4,1,2,1,3]
print(longest_common_subsequence(list1, list2))