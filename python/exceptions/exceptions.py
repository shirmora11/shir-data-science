def password_check(password):
    """function that return the complexity of a number but has to receive it as a str"""

    if len(password) < 8:
        raise Exception("password need to be 8 character or bigger")
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
    if has_number != True:
        raise Exception("has to have a number")
    if has_upper != True:
        raise Exception("has to have a upper character")
    if has_lower != True:
        raise Exception("has to have a lower character")
    if has_special != True:
        raise Exception("has to have a special character")
    complexity = has_upper + has_special + has_lower + has_number
    print(f'complexity for your password is: {complexity} out of 4')

password = "Shirmor11!"
password_check(password)