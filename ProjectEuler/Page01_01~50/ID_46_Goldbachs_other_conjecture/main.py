'''
Goldbach's other conjecture
Problem 46 
It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

9 = 7 + 2×12
15 = 7 + 2×22
21 = 3 + 2×32
25 = 7 + 2×32
27 = 19 + 2×22
33 = 31 + 2×12

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?


Answer:
5777
Completed on Fri, 29 Dec 2017, 14:58

'''
from math import sqrt

def isChristianGoldbach(num, primeList):
	for prime in primeList:
		square = sqrt(( num - prime ) / 2)
		if square != int(square):
			continue
		return square
	return False

def isOdd(num, primiList):
	sq = sqrt(num) + 1
	for prime in primeList:
		if prime > sq:
			return True
		if num % prime == 0:
			return False
	return True

i = 3
primeList = [2]

while ( True ):
	tempI = i
	i += 2
	if isOdd(tempI, primeList):
		primeList.append(tempI)
		print("a prime: %d" % (tempI))
		continue
	sq = isChristianGoldbach(tempI, primeList)
	if sq != False:
		print("%d\t = %d\t + 2 * %d * %d" % (tempI, tempI - 2 * sq * sq, sq, sq))
		continue
	print("what you want... %d" % (tempI)) 
	break