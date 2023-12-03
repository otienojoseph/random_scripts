class Robot:
    """Robot Class"""

    def __init__(self, name=None, build_year=2000):
        self.__name = name
        self.__build_year = build_year

    def say_hi(self):
        if self.__name:
            print("Hi, my name is " + self.__name)
        else:
            print("Hi, I am a robot without a name.")

    def get_name(self):
        return self.__name

    def set_name(self, name):
        self.__name = name
        print("name set!")

    def get_build_year(self):
        return self.__build_year

    def set_build_year(self, build_year):
        self.__build_year = build_year
        print("build_year set!")

    def __repr__(self):
        return "Robot(" + self.__name + ", " + self.__build_year + ")"

    def __str__(self):
        return "Robot(" + str(self.__name) + ", " + str(self.__build_year) + ")"


if __name__ == "__main__":
    x = Robot("Joseph", 2020)
    y = Robot("Otieno", 2021)
    for rob in [x, y]:
        rob.say_hi()
        if rob.get_name() == "Joseph":
            rob.set_build_year(2023)
        print("I was built in the year " + str(rob.get_build_year()) + ".")
