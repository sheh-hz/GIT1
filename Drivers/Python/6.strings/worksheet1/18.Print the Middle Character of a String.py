def middle_character(s):
    length = len(s)

    if length % 2 == 0:
        middle = s[length // 2 - 1:length // 2 + 1]
    else:
        middle = s[length // 2]

    return middle


s = "python"

print("Middle character:", middle_character(s))