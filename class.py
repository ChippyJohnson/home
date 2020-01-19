class vehic:
    pass
car=vehic()
print(car)

class Vehicle:
    def __init__(self,number_of_wheels, type_of_tank, seating_capacity, maximum_velocity): #constructor method
        self.number_of_wheels = number_of_wheels
        self.type_of_tank = type_of_tank
        self.seating_capacity = seating_capacity
        self.maximum_velocity = maximum_velocity
    @property
    def number_of_wheels(self):#getter
        return self.number_of_wheels
#    @number_of_wheels.setter
#   def number_of_wheels(self, number):#setter
#       self.number_of_wheels = number
        

v1= Vehicle(4, 'electric', 5, 250)
print("hai")
print(v1.number_of_wheels)
#v1.number_of_wheels=3
print(v1.number_of_wheels)

