import re

def find_urls(text):
    pattern = r'https?://[^\s]+'
    return re.findall(pattern, text)


text = "Check this link: https://openai.com and http://github.com"

print("URLs found:", find_urls(text))