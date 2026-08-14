def replace_words(text, replacements):
    for old_word, new_word in replacements.items():
        text = text.replace(old_word, new_word)

    return text


text = "I like apples and bananas."

replacements = {
    "apples": "oranges",
    "bananas": "grapes"
}

print(replace_words(text, replacements))