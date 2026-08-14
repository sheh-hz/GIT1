def uncommon_words(str1, str2):
    words1 = set(str1.split())
    words2 = set(str2.split())

    result = list(words1 ^ words2)

    return result


str1 = "red blue green"
str2 = "blue yellow red"

print("Uncommon words:", uncommon_words(str1, str2))