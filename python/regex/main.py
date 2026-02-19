import re
import collections

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

def find_single_number(nums):
    result = 0
    for num in nums:
        result ^= num
    print(result)
find_single_number([4, 1, 2, 1, 2])

nums = [1, 3, 2, 1, 4, 1, 2]
def freq(nums):
    """function that find the most common number in array """
    dic= {}
    for i , value in enumerate(nums):
        if value in dic:
            dic[value] += 1
        else:
            dic[value] = 1
    return max(dic,key=dic.get)
print(freq(nums))


def freq_map(lis):
    seen = set()
    dup = set()
    for num in lis:
        if num in seen:
            dup.add(num)
        else:
            seen.add(num)
    return list(dup)
print(freq_map([1, 2, 3, 1, 2, 10, 8, 2]))


def freq_map_col(lis):
    seen = collections.Counter(lis)
    result = ("".join(f"{char}{count}" for char ,count in seen.items()))
    print(result)
freq_map_col("aaaabbbccd")

def anagram (s1,s2):
    seen = {}
    for char in s1:
        seen[char] = seen.get(char, 0 ) + 1
    for char in s2:
        if char not in seen or seen[char] == 0:
            return False
        seen[char]-= 1
    return True


def dup_check(lis):
    seen = {}
    for char in lis:
        if char in seen:
            seen[char] += 1
        else:
            seen[char] = 1
    print([item for item in seen.keys()])


dup_check(["a", "b", "b", "a", "c", "d"])

