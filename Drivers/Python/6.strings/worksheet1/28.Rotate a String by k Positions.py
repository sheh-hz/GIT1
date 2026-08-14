def rotate_string(s, k):
    k = k % len(s)

    return s[-k:] + s[:-k]


s = "hello"
k = 2

print(rotate_string(s, k))