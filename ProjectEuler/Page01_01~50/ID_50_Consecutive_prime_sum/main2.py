from math import sqrt

def isPrime(num, primeList):
	limit = sqrt(int(num)) + 1
	for i in primeList:
		if i >= limit:
			return True
		if num % i == 0:
			return False
	return True

primeList = []
primeLimit = 1000000
primeSumList = []

print("generate primeList")
for i in range(2, primeLimit):
	if not isPrime(i, primeList):
		continue
	primeList.append(i)

print("generate primeSumList")
lastSum = primeList[0]
primeSumList.append(lastSum)
for i in primeList[1:]:
	lastSum += i
	primeSumList.append(lastSum)

tarPrime = 0
tarPrimeLength = 0
for idx0, value0 in enumerate(primeSumList):
	for idx1, value1 in enumerate(primeSumList[idx0 + 1:], idx0 + 1):
		currSum = value1 - value0
		if (currSum >= primeLimit):
			continue
		if not isPrime(currSum, primeList):
			continue
		length = idx1 - idx0
		if length < tarPrimeLength:
			continue
		tarPrime = currSum
		tarPrimeLength = length
		print("num: %d, length: %d" % (currSum, length))
		print(primeList[idx0:idx1])