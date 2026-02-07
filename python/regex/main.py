import re

def sum_extractor(string):
    """a function that receive a string with numbers in it and add up all the numbers if its above 100 youre good"""
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

def anagram(s1 , s2):
    seen = {}
    for char in s1:
        seen[char] = seen.get(char ,0)+1
    for char in s2:
        if char not in seen:
            return False
        seen[char] -= 1
        if seen[char]<0:
            return False
    return True

print(anagram("listen", "silent"))
print(anagram("hello", "world"))

def find_single_number(nums):
    result = 0
    for num in nums:
        result ^= num
    print(result)
find_single_number([4, 1, 2, 1, 2])
