'''
Prime permutations
Problem 49 
The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?


Answer:
296962999629
Completed on Sun, 31 Dec 2017, 14:53

'''

from math import sqrt

def isPrime(num, primeList):
	limit = sqrt(int(num)) + 1
	for i in primeList:
		if i >= limit:
			return True
		if num % i == 0:
			return False
	return True

def numToList(num):
	facList = []
	while num != 0:
		facList.append( num% 10 )
		num = int(num / 10)
	return facList

primeLimit = 10000
primeList = []
primeOver1000 = []
dic = {(0, ) : []}

# get all prime
for i in range(2, primeLimit):
	if not isPrime(i, primeList):
		continue
	primeList.append(i)

# get all prime over 1000
for i in primeList:
	if i < 1000:
		continue
	primeOver1000.append(i)

# find primes have the same digit
for i in primeOver1000:
	facList = numToList(i)
	facList.sort()
	facTuple = tuple(facList)
	dic.setdefault(facTuple, [])
	dic[facTuple].append(i)

sameFacList = []

# get increasing sequence
for key, value in dic.items():
	length = len(value)
	if length < 3:
		continue
	isIncreasing = False
	for i in range(1, length):
		for j in range(i):
			if not (value[i] + value[i] - value[j]) in value:
				continue
			print("%d%d%d" % (value[j], value[i], value[i] + value[i] - value[j]))