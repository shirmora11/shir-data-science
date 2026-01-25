def dup_check(string, letter):
    '''function that checks if there is a duplicate in string'''
    count = 0
    for i in range(len(string)):
        if letter == string[i]:
            count += 1
    print(f"count shows {count}")




def number_flip(number):
    """function that flips the number"""
    size = len(str(number))
    string_num = str(number)
    reversed =''
    for i in range(number):
        reversed = string_num[::-1]
    print(f"number is: {reversed}")


def temp_convertion(temp):
    new_temp = temp * 1.8 +32
    print(f'new_tempis:{new_temp}')


def leap_year(year):
    if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
        print(f'{year} is a leap year')
    else :
        print(f"{year} not a leap year")

def password_check(password):
    if len(password) < 8 :
        print("error password too short")
        return
    passw = str(password)
    complexity = 0
    for i in range (len(passw)):
        if passw.isupper():
            complexity += 1
        if passw.islower():
            complexity += 1
        if passw.isnumeric():
            complexity += 1
        if passw[i] == "@,#,%,&,!,?":
            complexity+= 1
    print(f"complexity for your password is {complexity}")
password = "123456aA!"
password_check(password)