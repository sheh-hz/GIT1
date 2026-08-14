from itertools import permutations

def all_permutations(s):
    result = []

    for p in permutations(s):
        result.append("".join(p))

    return result


s = "abc"

print(all_permutations(s))