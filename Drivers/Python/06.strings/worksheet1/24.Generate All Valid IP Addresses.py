def valid_ip_addresses(s):
    result = []

    def backtrack(index, parts):
        if len(parts) == 4:
            if index == len(s):
                result.append(".".join(parts))
            return

        # Remaining characters must be enough
        # and not more than needed
        remaining = len(s) - index
        parts_left = 4 - len(parts)

        if remaining < parts_left or remaining > parts_left * 3:
            return

        for length in range(1, 4):
            if index + length > len(s):
                break

            part = s[index:index + length]

            # Leading zero is not allowed
            if len(part) > 1 and part[0] == '0':
                continue

            value = int(part)

            if value <= 255:
                parts.append(part)

                backtrack(index + length, parts)

                parts.pop()

    backtrack(0, [])

    return result


s = "25525511135"

print(valid_ip_addresses(s))