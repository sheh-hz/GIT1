def minimum_rotations(s):
    rotated = s

    for count in range(1, len(s) + 1):
        rotated = rotated[1:] + rotated[0]

        if rotated == s:
            return count

    return 0


s = "abcde"

print(minimum_rotations(s))