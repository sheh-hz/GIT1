'''
class age:
    def __init__(self,name,age):
        self.name=name
        self.age=age
    def findage(self):
        print(self.name,2026-self.age, "year old")

obj=age("alice",2001)
obj.findage()


class Calculator:
    def add(self, a, b):
        return a + b
    def subtract(self, a, b):
        return a - b
    def multiply(self, a, b):
        return a * b
    def divide(self, a, b):
        if b == 0:
            return "Division by zero is not allowed"
        return a / b
calc = Calculator()
print("Addition =", calc.add(4, 5))
print("Subtraction =", calc.subtract(10, 3))
print("Multiplication =", calc.multiply(6, 7))
print("Division =", calc.divide(10, 2))



class Shape:
    def area(self):
        pass
    def perimeter(self):
        pass
class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius
    def area(self):
        return 3.14 * self.radius * self.radius
    def perimeter(self):
        return 2 * 3.14 * self.radius
class Square(Shape):
    def __init__(self, side):
        self.side = side
    def area(self):
        return self.side * self.side
    def perimeter(self):
        return 4 * self.side
class Triangle(Shape):
    def __init__(self, base, height, side1, side2):
        self.base = base
        self.height = height
        self.side1 = side1
        self.side2 = side2
    def area(self):
        return 0.5 * self.base * self.height
    def perimeter(self):
        return self.base + self.side1 + self.side2
c = Circle(3)
s = Square(4)
t = Triangle(6, 4, 5, 5)
print("Circle Area =", c.area())
print("Circle Perimeter =", c.perimeter())
print("Square Area =", s.area())
print("Square Perimeter =", s.perimeter())
print("Triangle Area =", t.area())
print("Triangle Perimeter =", t.perimeter())

'''