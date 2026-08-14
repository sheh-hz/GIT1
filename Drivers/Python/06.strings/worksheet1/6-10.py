import random
import string
from collections import Counter


# 1. Eliminate Duplicate Characters
def remove_duplicates(s):
    result = ""

    for char in s:
        if char not in result:
            result += char

    return result


# 2. Least Frequent Character
def least_frequent(s):
    count = Counter(s)
    minimum = min(count.values())

    return [char for char in count if count[char] == minimum]


# 3. Maximum Frequency Character
def maximum_frequent(s):
    count = Counter(s)
    maximum = max(count.values())

    return [char for char in count if count[char] == maximum]


# 4. Check Special Characters
def has_special_character(s):
    for char in s:
        if not char.isalnum():
            return True

    return False


# 5. Generate Random Strings Until Target is Formed
def generate_target(target):
    attempts = 0

    while True:
        random_string = ''.join(
            random.choice(string.ascii_lowercase)
            for _ in range(len(target))
        )

        attempts += 1

        if random_string == target:
            return random_string, attempts


# Main
s1 = "programming"
print("1. Original string:", s1)
print("   Without duplicates:", remove_duplicates(s1))


s2 = "statistics"
print("\n2. String:", s2)
print("   Least frequent character(s):", least_frequent(s2))


s3 = "banana"
print("\n3. String:", s3)
print("   Maximum frequency character(s):", maximum_frequent(s3))


s4 = "Hello@123"
print("\n4. String:", s4)

if has_special_character(s4):
    print("   Contains special character: Yes")
else:
    print("   Contains special character: No")


target = "abc"
result, attempts = generate_target(target)

print("\n5. Target:", target)
print("   Target generated:", result)
print("   Number of attempts:", attempts)