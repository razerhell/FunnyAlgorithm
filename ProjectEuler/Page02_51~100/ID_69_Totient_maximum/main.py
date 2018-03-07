'''
Totient maximum
Problem 69 
Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of numbers less than n which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.

n	Relatively Prime	φ(n)	n/φ(n)
2	1	1	2
3	1,2	2	1.5
4	1,3	2	2
5	1,2,3,4	4	1.25
6	1,5	2	3
7	1,2,3,4,5,6	6	1.1666...
8	1,3,5,7	4	2
9	1,2,4,5,7,8	6	1.5
10	1,3,7,9	4	2.5
It can be seen that n=6 produces a maximum n/φ(n) for n ≤ 10.

Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.


Answer:
510510
Completed on Wed, 7 Mar 2018, 18:26

'''

from math import sqrt

def getOnesPrimes(n:int, primeSetList:list):
	dif = set()
	baseNums = range(2, int(sqrt(n) + 1))
	for i in baseNums:
		if n % i != 0:
			continue
		j = int(n / i)
		try:
			dif.add(i)
		except MemoryError:
			print('error')
			exit()
	return dif
	
primeList = [0, 1]
maxValue = 2
maxValuen = 2
for i in range(2, 1000000):
	res = getOnesPrimes(i, primeList) - {1}
	primeList.append(res)
	otherRes = set(map(lambda x:int(i/x), res))
	
	base = set(range(1, i))
	
	for j in res:
		base -= set(range(j, i, j))
	
	for j in otherRes:
		base -= set(range(j, i, j))
	
	res = base
	
	currValue = i / len(res)
	if currValue < maxValue:
		continue
	maxValue = currValue
	maxValuen = i
	print(i, end='\t')
	print(currValue)
	print()