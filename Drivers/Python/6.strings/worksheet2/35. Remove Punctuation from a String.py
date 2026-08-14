import string

def remove_punctuation(s):
    result = ""

    for char in s:
        if char not in string.punctuation:
            result += char

    return result


s = "Hello, world! How are you?"

print(remove_punctuation(s))