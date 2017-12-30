'''
Self powers
Problem 48 
The series, 11 + 22 + 33 + ... + 1010 = 10405071317.

Find the last ten digits of the series, 11 + 22 + 33 + ... + 10001000.


Answer:
9110846700
Completed on Fri, 29 Dec 2017, 16:18

'''
POWER = 10
LIMIT = 1000

def powGetLast(num, power):
	BASE = 10 ** power
	mul = 1
	for i in range(num):
		mul *= num
		mul = mul % BASE
	return mul

def powGetLast10(num):
	return powGetLast(num, POWER)

i = 1
l = list(range(1, LIMIT + 1))
l = map(powGetLast10, l)

sum10 = 0
BASE = 10 ** POWER
for i in l:
	sum10 += i
	if sum10 <= BASE:
		continue 
	sum10 = sum10 % BASE

print(sum10)