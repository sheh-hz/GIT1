def is_binary_string(s):
    for char in s:
        if char not in ('0', '1'):
            return False
    return True


s = "101101"

if is_binary_string(s):
    print("Is binary string: Yes")
else:
    print("Is binary string: No")