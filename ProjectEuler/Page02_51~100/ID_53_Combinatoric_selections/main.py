'''
Combinatoric selections
Problem 53 
There are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, 5C3 = 10.

In general,

nCr =	
n!
r!(n−r)!
,where r ≤ n, n! = n×(n−1)×...×3×2×1, and 0! = 1.
It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.

How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are greater than one-million?


Answer:
4075
Completed on Sun, 14 Jan 2018, 18:12

'''


def csNotion(n, r, mullist):
	return mullist[n] / mullist[r] / mullist[n - r]


MAX_NUM = 100

mulList = [1]

overCount = 0

for i in range (1, MAX_NUM + 1):
	mulList.append(mulList[i-1] * i)

	for j in range(i + 1):
		res = csNotion(i, j, mulList)
		if res > 1000000:
			print("n: %d, r: %d, res: %d" % (i, j, res))
			overCount += 1

print("count: %d" % (overCount))