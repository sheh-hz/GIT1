'''a={101: 'Ravi', 102: 'Priya', 103: 'Amit'}
print(a)

d = {'x': 1, 'y': 2, 'x': 5}
print(d)

d = {'fruit': 'apple', 'veg': 'carrot'}
if 'fruit' in d:
    print(True)
else:
    print(False)


a="apple"
dic={}
for i in a:
    dic[i]=a.count(i)
print(dic)


marks = {'math': 75, 'science': 80}
print(marks['science'])
if 'history' not in marks:
    print("not found")



student = {'math': 90, 'english': 88, 'science': 92}
for i,j in student.items():
    print(i,j)


ages = {'Anil': 21, 'Sunita': 20}
ages['Anil']=22
print(ages)


info = {'a': 10, 'b': 20}
for i in info:
    info[i]=100
print(info)


salaries = {'A': 20000, 'B': 30000}
for i in salaries:
    salaries[i]=salaries[i] + (salaries[i]*10)/100
print(salaries)
salaries['C']=25000
print(salaries)


cities = {'Delhi': 18000000, 'Mumbai': 20000000}
cities['Bangalore']=12000000
print(cities)

user = {'name': 'Riya'}
if 'statuse' not in user:
    user['status']='active'
print(user)



l=['dog', 'cat', 'rabbit']
d={}
for i in l:
    c=len(i)
    d[i]=c
print(d)


d1 = {'x': 1} 
d2 = {'y': 2}
d3=d1.copy()
d3.update(d2)
print(d3)


marks = {'math': 80, 'science': 85}
del marks['math']
print(marks)


info = {'name': 'Amit', 'city': 'Pune'}
info.pop('name')
print(info)

d = {'x': 1, 'y': 2}
d.clear()
print(d)



d = {'a': 10, 'b': 20, 'c': 30}
for i in d.keys():
    print(i)
d = {'a': 10, 'b': 20, 'c': 30}
for i in d.values():
    print(i)
d = {'a': 10, 'b': 20, 'c': 30}
for i,j in d.items():
    print(i,j)

scores = {'math': 75, 'science': 55, 'english': 82}
for i,j in scores.items():
    if j>=60:
        print(i)

'''

d = {'p': 2, 'q': 3}
c=d.copy()
print(c)
a = {'x': [1, 2]}
b = a
b['x'].append(3)
print("a =", a)
print("b =", b)


students = {
    'Rahul': {'age': 16, 'marks': {'math': 90, 'english': 88}},
    'Simran': {'age': 15, 'marks': {'math': 95, 'english': 92}}
}
students['Simran']['marks']['science'] = 93
print(students)