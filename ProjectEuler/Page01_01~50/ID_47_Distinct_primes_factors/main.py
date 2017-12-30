'''
Distinct primes factors
Problem 47 
The first two consecutive numbers to have two distinct prime factors are:

14 = 2 × 7
15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.

Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?


Answer:
134043
Completed on Fri, 29 Dec 2017, 15:56

'''

from math import sqrt

def getPrimeFactor(num, primeList, facMap):
	primeLimit = sqrt(num) + 1
	for prime in primeList:
		if (prime > primeLimit):
			break
		sub = num / prime
		if sub != int(sub):
			continue;
		# it is a prime number
		if sub == 1:
			return set([num])

		return facMap[int(sub)] | set([prime])

	# it is a prime number
	return set([num])

primeL = []
facMap = [set([0]), set([1])]
i = 2
consecutiveCount = 0
while ( True ):
	tempI = i
	i += 1

	# get prime factor
	facSet = getPrimeFactor(tempI, primeL, facMap)
	lenSet = len(facSet)
	if (lenSet == 1):
		primeL.append(tempI)
	facMap.append(facSet)

	# print
	print("%d:\t%d" % (tempI, lenSet))
	print(facSet)
	print()

	# find consecutive 
	if lenSet != 4:
		consecutiveCount = 0
		continue
	consecutiveCount += 1
	if consecutiveCount == 4:
		break