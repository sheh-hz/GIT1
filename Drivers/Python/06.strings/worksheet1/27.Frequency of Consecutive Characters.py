def consecutive_frequency(s):
    result = {}

    i = 0

    while i < len(s):
        char = s[i]
        count = 1

        while i + 1 < len(s) and s[i + 1] == char:
            count += 1
            i += 1

        result[char] = count
        i += 1

    return result


s = "aabccddd"

print(consecutive_frequency(s))