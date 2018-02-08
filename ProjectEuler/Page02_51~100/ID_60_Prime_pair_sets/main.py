'''
Prime pair sets
Problem 60 
The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes and concatenating them in any order the result will always be prime. For example, taking 7 and 109, both 7109 and 1097 are prime. The sum of these four primes, 792, represents the lowest sum for a set of four primes with this property.

Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.


Answer:
26033
Completed on Thu, 8 Feb 2018, 13:04

'''


from math import sqrt
from time import clock

def isPrime(n:int, primes:list):
	baseMax = int(sqrt(n)) + 1
	for i in primes:
		if i >= baseMax:
			return True
		if n % i == 0:
			return False
	if len(primes) == 0 or baseMax < primes[-1]:
		return True
	for i in range(primes[-1], baseMax):
		if n % i == 0:
			return False

def getSingleElementSet(n:int):
	return tuple([n])

def compoundNum(t:tuple):
	n0 = t[0]
	n1 = t[1]
	return n0 * 10 ** len(str(n1)) + n1

MAX_POWER = 4
TARGET_SIZE = 5
MAX_NUM = 10 ** MAX_POWER
MAX_PRIME = 10 ** (MAX_POWER * 2)
primes = list()
primeSet = list()

# 求得质数列表
for i in range(2, MAX_PRIME):
	if isPrime(i, primeSet):
		primeSet.append(i)
for i in primeSet:
	if i > MAX_NUM:
		break
	primes.append(i)
primeSet = set(primeSet)
print("compelete prime list")

# 求得质数列表的笛卡儿积
from itertools import product
from itertools import permutations
from copy import deepcopy
res = list(map(getSingleElementSet, primes))
for i in range(2, TARGET_SIZE + 1):
	resBk = list()
	for j in product(res, primes):
		x = deepcopy(j)
		tempSet = set([k for k in x[0]])
		tempElement = x[1]
		tempSet.add(tempElement)
		if len(tempSet) < i:
			continue

		isPair = True
		for k in permutations(tempSet, 2):
			res = compoundNum(k)
			if res in primeSet:
				continue
			'''
			if isPrime(res, primes):
				continue
			'''
			isPair = False
			break

		if not isPair:
			continue

		tempSet = list(tempSet)
		tempSet.sort()
		resBk.append(tuple(tempSet))
	res = list(set(resBk))
	print(res)
	print()

