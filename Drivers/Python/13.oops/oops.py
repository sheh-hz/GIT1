'''
class Note:
    def __init__(self,title,content):
        self.title=title
        self.content=content
    def book(self):
        print(self.title)
        print(self.content)
obj = Note("Meeting Notes", "Discuss project status with team.")
obj.book()
obj2=Note("Grocery List", "Eggs, Milk, Bread")
obj2.book()


class magiccreature:
    pass

obj=magiccreature
print(type(obj))


class vehicles:
    def __init__(self,str):
        self.str=str
    def buses(self):
        print(self.str ," is moving")

class Bus(vehicles):
    pass

b=Bus("car")
b.buses()

v=vehicles("van")
v.buses()
        


class Shape:
    def draw(self):
        print("Drawing a Shape")
class Circle(Shape):
    def draw(self):
        print("Drawing a Circle")
class Square(Shape):
    def draw(self):
        print("Drawing a Square")
c = Circle()
s = Square()
c.draw()
s.draw()



class student:
    schoolname="ABC school"
    def __init__(self,name):
        self.name=name
        
s1=student("mmm")
s2=student("kkk")
print(s1.name,s1.schoolname)
print(s2.name,s2.schoolname)




class Vehicle:
    pass
class Bus(Vehicle):
    pass
b = Bus()
print(isinstance(b, Bus))
print(isinstance(b, Vehicle))
print(isinstance(b, str))


class Vehicle:
    pass
class Bus(Vehicle):
    pass
b = Bus()
print(issubclass(Bus,Vehicle))



      
class Shape:
    def area(self):
        print("Area of Shape")
class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius
    def area(self):
        print("Area of Circle =", 3.14 * self.radius * self.radius)
class Square(Shape):
    def __init__(self, side):
        self.side = side
    def area(self):
        print("Area of Square =", self.side * self.side)
c = Circle(5)
s = Square(4)
c.area()
s.area()



class Circle:
    def __init__(self, radius):
        self.radius = radius
    def area(self):
        return 3.14 * self.radius * self.radius
    def perimeter(self):
        return 2 * 3.14 * self.radius
c = Circle(3)
print("Area =", c.area())
print("Perimeter =", c.perimeter())

'''
