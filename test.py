import random

three = 0
four = 0
five = 0
raw = [[random.randint(0, 1) for x in range(5)] for y in range(1000)]

for match in raw:
    if sum(match[:3]) == 0 or sum(match[:3]) == 3: three += 1
    elif sum(match[:4]) == 1 or sum(match[:4]) == 3: four += 1
    else: five += 1

s = three + four + five
print(three / s, four / s, five / s)