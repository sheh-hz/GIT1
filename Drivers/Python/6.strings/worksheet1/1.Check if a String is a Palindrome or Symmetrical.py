string = "madam"

# Check palindrome
if string == string[::-1]:
    print("Palindrome: Yes")
else:
    print("Palindrome: No")

# Check symmetry
n = len(string)

if n % 2 == 0:
    symmetrical = string[:n//2] == string[n//2:]
else:
    symmetrical = string[:n//2] == string[n//2+1:]

print("Symmetrical:", "Yes" if symmetrical else "No")