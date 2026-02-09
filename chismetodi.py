import math

#задание 1
#8 a)

# a = 2.29
# x = 16/17
#
# c = math.sqrt(11)
# b = 3.32
#
# y = abs(x - a)
# u = abs(c-b)
#
# o = y/abs(a)
# p = u/abs(b)
#
# if (o > p):
#     print("p точнее чем o")
# else:
#     print("o точнее чем p")

#задание 1
#8 b)

# a = 0.75244
# b = 0.00013
#
# c = round (a, 4)
# d = 0.5 * 0.0001
#
# print(c,d)

#задание 1
#8 c)

# a = 5.374
# b = 0.001
#
# c = 0.001 / abs(5.374)
#
# print(c)
#
#

#задание 2
#8

a = 18.0354
b = 3.7251
c = 0.071

abs_1 = 0.0001
abs_2 = 0.0001
abs_3 = 0.001

otn_1 = abs_1 / abs(a)
otn_2 = abs_2 / abs(b)
otn_3 = abs_3 / abs(c)

des_1 = (b - c)
abs_des_1 = abs_2 + abs_3
otn_des_1 = abs_des_1/abs(des_1)

des_2 = math.sqrt(des_1)
abs_des_2 = 0.5 * otn_des_1
otn_des_2 = abs_des_2 / abs(des_2)

des_3 = math.log(a)
#"производная логарифма"
def ln_derivative(des_3):
    if des_3 <= 0:
        return "x > 0"
    return 1 / des_3

abs_des_3 = abs(ln_derivative(des_3)) * abs_1
otn_des_3 = abs_des_3 / abs(des_3)

des_4 = des_3 + b
abs_des_4 = abs_des_3 + abs_3
otn_des_4 = abs_des_4 / abs(des_4)

des_5 = des_2 / des_4
abs_des_5 =



