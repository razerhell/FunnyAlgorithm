'''
Totient permutation
Problem 70 
Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of positive numbers less than or equal to n which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
The number 1 is considered to be relatively prime to every positive number, so φ(1)=1.

Interestingly, φ(87109)=79180, and it can be seen that 87109 is a permutation of 79180.

Find the value of n, 1 < n < 107, for which φ(n) is a permutation of n and the ratio n/φ(n) produces a minimum.


Answer:
8319823
Completed on Wed, 7 Mar 2018, 20:43

list先快后慢，减速度较大
dict减速度较小，整体效率低于list

https://brilliant.org/wiki/eulers-totient-function/
'''

primeList = [{}, {}]
Max_Num = 10 ** 7
listSize = Max_Num + 1
maxValue = -1

from math import sqrt

def getPrime(n:int, pList:list):
	for i in range(2, int(sqrt(n) + 1)):
		if n % i != 0:
			continue
		return pList[int(n / i)] | {i}
	return None

def calTotient(n:int, pl:list):
	res = n
	for i in pl:
		res = int(res * (i - 1) / i)
	return res

def intToPer(n:int):
	return ''.join(sorted(list(str(n))))

def isPermutation(n1:int, n2:int):
	return intToPer(n1) == intToPer(n2)

for i in range(2, listSize):
	res = getPrime(i, primeList)

	totientCount = 0
	if res:
		primeList.append(res)
		totientCount = calTotient(i, res)
	else:
		primeList.append({i})
		totientCount = i - 1

	if not isPermutation(i, totientCount):
		continue

	currValue = totientCount / i
	if currValue < maxValue:
		continue

	maxValue = currValue

	print(i, end = '\t')
	print(totientCount)