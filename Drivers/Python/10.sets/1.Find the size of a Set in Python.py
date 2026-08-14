bag = {"ball", "car", "puzzle", "car", "yo-yo"}
c=set(bag)
print(len(c))

animals = {"lion", "tiger", "bear"}
print(animals)
print(animals)

scores = {3, 7, 10, 2, 9}
print(max(scores))
print(min(scores))

toys = {"robot", "car", "doll"}
# remove "doll"
toys.remove("doll")
print(toys)

my_favs = ["Tom", "Jerry", "Ben 10"]
friend_favs = ["Powerpuff", "Jerry", "Scooby"]
common=set(my_favs)&set(friend_favs)
print(common)

a = ["Toy Story", "Frozen", "Moana"]
b = ["Moana", "Coco", "Frozen"]
c = ["Frozen", "Moana", "Up"]
common=set(a)&set(b)&set(c)
print(common)

old_hw = ["math", "science", "art"]
new_hw = ["math", "history", "science"]
missing = set(old_hw) - set(new_hw)
additional = set(new_hw) - set(old_hw)
print("Missing:", missing)
print("Additional:", additional)

last_week = ["hide", "seek", "tag"]
this_week = ["hide", "seek", "jump", "run"]
week=set(this_week)-set(last_week)
print(week)

yesterday = [1, 2, 3, 4]
today = [1, 2, 4]
lost = set(yesterday) - set(today)
print("Lost:", *lost)

text = "Hello World"
vowels = {'a', 'e', 'i', 'o', 'u'}
count = 0
for ch in text.lower():
    if ch in vowels:
        count += 1
print(count)