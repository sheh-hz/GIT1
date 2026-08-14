
stock = {'apples': 14, 'bananas': 22, 'rice': 12}
query = 'apples'
if query in stock:
    print("Yes,", query, "are in stock!")
else:
    print("No,", query, "are not in stock!")


pets = {'Harry': 'owl', 'Ron': 'rat'}
query = 'Hermione'
if query in pets:
    print(pets[query])
else:
    print("No record, maybe try another student!")

auction = {'lot1': 'coin', 'lot2': 'stamp', 'lot3': 'coin', 'lot4': 'comic'}
l=[]
for i in auction.values():
    if i not in l:
        l.append(i)
print(l)


sum=0
inventory = {'box': 30, 'crate': 22, 'pallet': 8}
for i in inventory.values():
    sum+=i
print(sum)


north = {'Winterfell': 1000, 'The Eyrie': 800}
south = {'The Eyrie': 1200, "King's Landing": 2500}
north.update(south)
print(north)


codes = {'alpha': 'ok', 'beta': 'wait'}
new_labels = {'alpha': 'red', 'beta': 'blue'}
result = {}
for key in codes:
    result[new_labels[key]] = codes[key]
print(result)


spells = {'fireball': 5, 'healing': 10, 'curse': 2}
banned = ['curse', 'fireball']
for spell in banned:
    if spell in spells:
        del spells[spell]
print(spells)


orders = ['latte', 'espresso', 'latte', 'tea', 'espresso', 'latte']
menu = {}
for item in orders:
    if item in menu:
        menu[item] += 1
    else:
        menu[item] = 1
print(menu)


profile = {'info': {'name': 'Sam', 'phone': '555-1234'}}
new_phone = '555-9999'
profile['info']['phone'] = new_phone
print(profile)


names = ['Alice', 'Bob', 'Eve']
seats = [5, 12, 8]
guests = {}
for name, seat in zip(names, seats):
    guests[name] = seat
print(guests)