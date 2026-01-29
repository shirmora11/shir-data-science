def dup_check(string, letter):
    """function that checks if there is a duplicate in string"""
    count = 0
    for s in string:
        count = string.count(letter)
    print(f"count shows {count}")
    return count


def number_flip(number):
    """function that flips the number"""
    string_num = str(number)
    reversed =''
    for i in range(number):
        reversed = string_num[::-1]
    return reversed


def temp_convertion(temp):
    """function that convert the temp from Celsius to Fahrenheit """
    new_temp = temp * 1.8 + 32
    return new_temp


def leap_year(year):
    """function that checks if its leap year"""
    if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
        print(f'{year} is a leap year')
        return True
    else :
        print(f"{year} not a leap year")
        return False


def password_check(password):
    """function that return the complexity of a number but has to receive it as a str"""

    if len(password) < 8:
        print("error password too short")
        return False

    has_number = False
    has_upper = False
    has_special = False
    has_lower = False

    for char in password:
        if char.isnumeric():
            has_number = True
        elif char.isupper():
            has_upper = True
        elif char.islower():
            has_lower = True
        elif not char.isalnum():
            has_special = True
    complexity = has_upper + has_special + has_lower + has_number
    if complexity == 4:
        return True
    else: return False

def sum_divisors(num):
    """function that returns the sum of divisors"""
    sum = 0
    for i in range(1,num):
        if num % i == 0:
            sum += i
    print(f'the sum of all divisors are:{sum}')

def bills(change):
    """function that checks how much change do you need to return"""
    currency = {
        200: "two hundred",
        100: "one hundred",
        50: "fifty",
        20: "twenty",
        10: "ten",
        5: "five",
        2: "two",
        1: "one"
        }

    answers = {}
    for value in currency:
        if change >= value:
            num_of_bills = change // value
            answers[currency[value]] = num_of_bills
            change = change % value
    for name, amount in answers.items():
        print(f"You need {amount} of {name}")

def prime(num):
    """function that returns if a number is prime or not"""
    count = 0
    for i in range(1,num):
        if num % i == 0:
            count +=1
    if count > 1:
        print(f"{num} is not prime")
    if count == 1:
        print(f"{num} is prime")
