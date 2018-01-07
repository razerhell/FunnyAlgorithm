'''
Prime digit replacements
Problem 51 
By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.

Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.


Answer:
121313
Completed on Sun, 7 Jan 2018, 19:56

'''

from math import sqrt

def isPrime (num, primeList):
	limit = int(sqrt(num) + 1)
	for i in primeList:
		if num % i == 0:
			return False
		if i >= limit:
			break
	return True

def countDigit(num):
	res = dict()
	digit = 0
	while num != 0:
		n = num % 10
		num = int(num / 10)
		l = []
		l.append(digit)
		if res.get(n):
			res[n] += l
		else:
			res[n] = l
		digit += 1
	return res

def numToDigit(num):
	res = []
	while num != 0:
		n = num % 10
		num = int ( num / 10)
		res.append(n)
	return res

def numToTuple(num):
	digits = countDigit(num)
	d = numToDigit(num)
	res = []
	digitSet = list()
	digitSetPlus = list()
	for i in digits.values():
		digitSet.append(i)
		if len(i) < 2:
			continue
		subset = getSubSet(i)
		for j in subset:
			digitSetPlus.append(j)

	if num == 56003:
		print(digitSetPlus)

	for i in digitSet + digitSetPlus:
		dbk = d[:]
		for j in i:
			dbk[j] = -1
		res.append(tuple(dbk))
	return res

def insertDict(d, t, num):
	l = set()
	l.add(num)
	if (d.get(t)):
		if l in d[t]:
			return
		d[t] = d[t] | l
	else:
		d[t] = l

def numToBase2(num):
	res = []
	while num != 0:
		n = num % 2
		res.append(n)
		num = int(num/2)
	return res

def getSubSet(s):
	res = list()
	l = list(s)
	currL = len(l)
	maxLimit = 2 ** currL - 1
	for i in range (1, maxLimit):
		r = numToBase2(i)
		ll = list()
		for j, k in enumerate(r):
			if not k == 1:
				continue
			ll.append(l[j])
		res.append(ll)
	return res

MAX_NUM = 1000000
primeList = []
stuffHash = dict()
stuffSetState = 0
for i in range(2, MAX_NUM):
	if not isPrime(i, primeList):
		continue
	primeList.append(i)
	tupleList = numToTuple(i)
	currLen = len(tupleList)
	if (currLen > stuffSetState):
		stuffHash.clear()
		stuffSetState = currLen
	for t in tupleList:
		insertDict(stuffHash, t, i)


maxCount = 0
for k, v in stuffHash.items():
	currLen = len(v)
	if currLen < maxCount:
		continue
	maxCount = currLen
	print()
	print(k)
	print(v)
	if currLen == 8:
		print("supprise...")
		print(min(v))
		break