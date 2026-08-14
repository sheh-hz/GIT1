def snake_to_pascal(s):
    words = s.split("_")

    result = ""

    for word in words:
        result += word.capitalize()

    return result


s = "my_variable_name"

print(snake_to_pascal(s))