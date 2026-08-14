def convert_values():
    integer_value = 123
    string_value = "456"

    integer_to_string = str(integer_value)
    string_to_integer = int(string_value)

    print("Integer to string:", repr(integer_to_string))
    print("String to integer:", string_to_integer)


convert_values()