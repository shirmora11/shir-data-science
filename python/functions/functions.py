from functools import reduce


def remove_words(lists, *words):
    """function that remove specific words from a given list"""
    new_list = list(filter(lambda word: word not in words, lists))
    return new_list


def num_sort(lists):
    """function that returns a sorted list of string(numbers)"""
    lists.sort(key=lambda x: int(x))


def sum_of_list(lists):
    """function that calculate the sum of the positive and negative number of a list"""
    pos_list = sum(list(filter(lambda x: x < 0, lists)))
    neg_list = sum(list(filter(lambda x: x > 0, lists)))
    return pos_list, neg_list


def square_list(list):
    """function that squares all the numbers in the list"""
    new_list = [item for item in (map(lambda x: x * x, list))]


def discount(dic):
    """function that receive a dictionary with names and prices and return them
    with 10 percent discount"""
    new_dict = {k: v * 0.9 for k, v in dic.items()}
    return new_dict


def gimatria(word):
    """function that give you the gematria value of your word"""
    alef = {'א': 1, 'ב': 2, 'ג': 3, 'ד': 4, 'ה': 5,
            'ו': 6, 'ז': 7, 'ח': 8, 'ט': 9, 'י': 10,
            'כ': 20, 'ל': 30, 'מ': 40, 'נ': 50, 'ס': 60,
            'ע': 70, 'פ': 80, 'צ': 90, 'ק': 100, 'ר': 200,
            'ש': 300, 'ת': 400, 'ך': 500, 'ם': 600, 'ן': 700, 'ף': 800, 'ץ': 900}
    val = sum([alef.get(char, 0) for char in word])
    return val


def luhn_algo(code):
    """function that double every second number start from the right if the answer is
    bigger than 9 it subtracts 9 and take the sum of all digits"""
    code.reverse()
    new_list = []
    for idx , num in enumerate(code):
        if idx % 2 == 1:
            num *= 2
            if num > 9:
                num -= 9
        new_list.append(num)
    print(new_list)
    if sum(new_list) % 10 == 0:
        print("valid")
    else:
        print("not valid")
    print(sum(new_list))
luhn_algo([7, 1, 4, 2, 7, 3, 9, 8, 7, 1, 3])
