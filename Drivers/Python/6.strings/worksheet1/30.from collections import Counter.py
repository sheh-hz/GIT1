from collections import Counter

def word_frequency(text):
    return dict(Counter(text.split()))


text = "apple apple orange"

print(word_frequency(text))