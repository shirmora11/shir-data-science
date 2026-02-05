import re

def sum_extractor(string):
    """a function that recive a string with numbers in it and add up all the numbers if its above 100 youre good"""
    pattern = r"\d+"
    numbers = re.findall(pattern, string)
    nums = [int(num) for num in numbers]

    if sum(nums) < 100:
        print("sum too low")
    else:
        print(" ".join(numbers))


sum_extractor("shir11adi42carmit70")

def clean_address(address):
    """a function that receive a messy address and clean it up"""
    pattern = r"[a-zA-Z0-9]+"
    clean = re.findall(pattern,address)
    print(" ".join(clean))

clean_address("Main#St. 123!!!")
