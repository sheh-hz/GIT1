def find_word_position(text, word):
    return text.find(word)


text = "welcome to python"
word = "python"

print("Position:", find_word_position(text, word))