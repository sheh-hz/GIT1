def convert_number_words(text):
    numbers = {
        "zero": "0",
        "one": "1",
        "two": "2",
        "three": "3",
        "four": "4",
        "five": "5",
        "six": "6",
        "seven": "7",
        "eight": "8",
        "nine": "9"
    }

    words = text.split()

    for i in range(len(words)):
        word = words[i]

        # Remove punctuation temporarily
        punctuation = ""

        if word[-1] in ".,!?":
            punctuation = word[-1]
            word = word[:-1]

        if word in numbers:
            words[i] = numbers[word] + punctuation

    return " ".join(words)


text = "I have one apple and two oranges."

print(convert_number_words(text))