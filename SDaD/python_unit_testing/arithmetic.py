def summ(a, b):
    return a + b


def subtraction(a, b):
    return a - b


def multiplication(a, b):
     return a * b


def division(a, b):
     if b == 0:
          raise ZeroDivisionError("Can't divide by zero")
     return a / b
 
 
def int_division(a, b):
     if b == 0:
          raise ZeroDivisionError("Can't divide by zero")
     return a // b


def modulo(a, b):
     return a % b


def power(a, b):
     return a ** b
