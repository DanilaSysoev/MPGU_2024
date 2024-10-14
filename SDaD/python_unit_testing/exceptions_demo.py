class MyException(Exception):
    def __init__(self, message) -> None:
        super().__init__(message)


def h():
    print("h До срабатывание исключения")
    a = int(input())
    if a > 0:
        raise MyException("Error at h(): a is positive")
    elif a < 0:
        raise ValueError("Error at h(): a is negative")
    else:
        raise TypeError("Error at h(): a is zero")
    print("После срабатывания исключения (никогда не сработает)")


def g():
    print("g До вызова h()")
    h()
    print("После вызова h()")


def f():
    print("f До вызова g()")
    try:
        g()
    except MyException as e:
        print(e)
    except BaseException as e:
        print(e)
    print("После вызова g()")


def main():
    print("main До вызова f()")
    f()
    print("После вызова f()")


if __name__ == '__main__':
    main()
