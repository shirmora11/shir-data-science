


def remove_list(list):
    """function that clears list"""
    return list.clear()
def string_to_letters(string):
    """function that breakdown string to letters"""
    answer = {}
    for char in string:
        answer[char] = answer.get(char, 0)+1
    print(f"{answer}")

def two_lists(first, second):
    """function that turns two lists to one with all the
    elements that were in both"""
    third = [item for item in first if item in second]
def unique_list(dict):
    """function that recive a dictionary and return a list with all unique values"""
    list = (set(dict.values()))
    print(list)
    return list
def left_rotation(list):
    """function that receive a list and rotate it left one time"""
    new_list = list[::-1]
def jump_remove(list):
    """a function that jumps 2 places every time until the list is empty"""
    while (len(list) != 0):
        for item in list[::2]:
            if item in list:
                print(item)
                list.remove(item)
    return list
def dict_to_list(dict):
    """a function that receive a dict and turns the key value pair to a list of tuples"""
    listof = tuple(dict.items())
    print(listof)
def max_min(dict):
    """function that gives the max and min of the dictionary"""
    ma = max(dict.values())
    mi = min(dict.values())
    key_max = [key for key, value in dict.items() if value == ma]
    key_min = [key for key, value in dict.items() if value == mi]
    print(key_max,key_min)
max_min({1:2,2:3,3:5,6:10,7:0})
def not_common_letters(first,second):
    """a function that prints all the letters of the first string that wasn't used in the second one"""
    third = [item for item in first if item not in second]
    print(third)


