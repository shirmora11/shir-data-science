def dup_check(string, letter):
    """function that checks if there is a duplicate in string"""
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
    print(f"number  reversed is: {reversed}")


def temp_convertion(temp):
    new_temp = temp * 1.8 +32
    print(f'new_temp is:{new_temp}')


def leap_year(year):
    if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
        print(f'{year} is a leap year')
    else :
        print(f"{year} not a leap year")


def password_check(password):
    """function that return the complexity of a number but has to receive it as a str"""

    if len(password) < 8:
        print("error password too short")
        return

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
    print(f'complexity for your password is: {complexity} out of 4')

def sum_divisors(num):
    sum = 0
    for i in range(1,num):
        if num % i == 0:
            sum += i
    print(f'the sum of all divisors are:{sum}')

def bills(change):
    bills_coins = 0
    two_hun = 0
    one_hun = 0
    fifty = 0
    twenty = 0
    ten = 0
    five = 0
    two = 0
    one = 0
    for i in range(1,change):
        if change > 200:
            two_hun += 1
            bills_coins +=1
            change -= 200
        elif change > 100:
            one_hun += 1
            bills_coins +=1
            change -= 100
        elif change > 50:
            fifty += 1
            bills_coins += 1
            change -= 50
        elif change > 20:
            twenty += 1
            bills_coins +=1
            change -= 20
        elif change > 10:
            ten += 1
            bills_coins +=1
            change -= 10
        elif change > 5:
            five += 1
            bills_coins +=1
            change -= 5
        elif change > 2:
            two += 1
            bills_coins += 1
            change -= 2
        elif change > 2:
            one += 1
            bills_coins += 1
            change -= 1
    print(f"the change is:{bills_coins} this anount of bills and coins on the minimum")
    print(f"this is the breakdown:{two_hun} two hundred , {one_hun} one hundred , {fifty} fifty , {twenty} twenty , {ten} ten , {five} five , {two} two , {one} one ")

def prime(num):
    count = 0
    for i in range(1,num):
        if num % i == 0:
            count +=1
    if count > 1:
        print(f"{num} is not prime")
    if count == 1:
        print(f"{num} is prime")
