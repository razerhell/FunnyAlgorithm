'''
Pandigital prime
Problem 41 
We shall say that an n-digit number is pandigital if 

it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?


Answer:
7652413
Completed on Mon, 25 Dec 2017, 15:57

'''

primes = list([2, 3, 5, 7])
pandigitalPrime = list()

import math

def isPrime(num, baseList):
	base = int(math.sqrt(num)) + 1
	for i in baseList:
		if i > base :
			return True
		if num % i == 0:
			return False

def numToList(num):
	res = list()
	while num != 0:
		base = num % 10
		res.append(base)
		num = int(num/10)
	return res

def isPandigital(num):
	res = numToList(num)
	l = len(res)
	temp = list(range(1, l + 1))
	if (l != len(temp)):
		return False
	return	len(set(res) & set(temp)) == l

for i in range(11, 10000000):
	if isPrime(i, primes):
		primes.append(i)
		if isPandigital(i):
			print(i)