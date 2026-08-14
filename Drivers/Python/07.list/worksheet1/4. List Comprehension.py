fruits=["apple","banana","cherry","kiwi","mango"]

fruits_with_a = [fruit for fruit in fruits if "a" in fruit]
print("Fruits with 'a':", fruits_with_a)
uppercase_fruits = [fruit.upper() for fruit in fruits]
print("Uppercase fruits:", uppercase_fruits)
new_fruits = ["orange" if fruit == "banana" else fruit for fruit in fruits]
print("Updated fruits:", new_fruits)