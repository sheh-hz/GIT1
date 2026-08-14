def character_position(words, k, char):
    word = words[k - 1]

    return word.find(char) + 1


words = ["hello", "world"]
k = 2
char = "r"

print("Position:", character_position(words, k, char))