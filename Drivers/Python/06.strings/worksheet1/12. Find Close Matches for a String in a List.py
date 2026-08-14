from difflib import SequenceMatcher

def close_matches(target, words):
    result = []

    for word in words:
        similarity = SequenceMatcher(None, target, word).ratio()

        if similarity >= 0.7:
            result.append(word)

    return result


target = "apple"
words = ["apply", "apples", "ape", "maple"]

print("Close matches:", close_matches(target, words))