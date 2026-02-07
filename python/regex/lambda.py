
def celsius_to_fahrenheit(celsius_list):
    answer = [(c * 1.8 + 32) for c in celsius_list]
    print(answer)
    secop = list(map(lambda x:x*1.8 +32,celsius_list))
    print(secop)

celsius_to_fahrenheit([10, 20, 30, 40, 50])

def grade_check(grades):
    check = list(filter(lambda x:x<60,grades))
    bonus = [(item+5) for item in check]
    print(check)
    print(bonus)
grade_check([55, 80, 40, 92, 75, 60, 42])
def oneline(grades):
    print(list((item+5)for item in grades if item > 60))
oneline([55, 80, 40, 92, 75, 60, 42])