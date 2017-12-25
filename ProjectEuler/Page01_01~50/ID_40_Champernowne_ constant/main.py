'''
Champernowne's constant
Problem 40 
An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the following expression.

d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000

Answer:
210

Completed on Wed, 25 Dec 2017, 9:20

'''
def numToList(num):
    numList = []
    while num != 0:
        n = num % 10
        numList.append(n)
        num = int(num / 10)
    return numList

stuffNum = 0
base = 10
res = 1
i = 0

while i <= 10000:
    stuffNum += 1
    nl = numToList(stuffNum)
    while nl:
        n = nl.pop()
        i += 1
        if i != base:
            continue
        base *= 10
        res *= n
        print("%d, %d" % (i, n))

print(res)