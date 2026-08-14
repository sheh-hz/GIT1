def swap_comma_dot(s):
    s = s.replace(",", "#")
    s = s.replace(".", ",")
    s = s.replace("#", ".")

    return s


s = "23,45.89,78.90"

print(swap_comma_dot(s))