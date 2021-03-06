'''
Pentagon numbers
Problem 44 
Pentagonal numbers are generated by the formula, Pn=n(3n−1)/2. The first ten pentagonal numbers are:

1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ...

It can be seen that P4 + P7 = 22 + 70 = 92 = P8. However, their difference, 70 − 22 = 48, is not pentagonal.

Find the pair of pentagonal numbers, Pj and Pk, for which their sum and difference are pentagonal and D = |Pk − Pj| is minimised; what is the value of D?


Answer:
5482660
Completed on Fri, 29 Dec 2017, 10:32
'''

import math

def nToPentagonNumbers(num):
	return int( ( 3 * num * num - num) / 2 )


def pentagonNumbersToN(num):
	return ( 0.5 + math.sqrt(0.25 + 6 * num )) / 3 


limit = 100000
pnList = [int] * limit
for i in range(limit):
	pnList[i] = nToPentagonNumbers( i + 1 )
print("pnList created...")

# i =	Pn1 + Pn2
for i in pnList:
	# j =	Pn1
	for j in pnList:
		if j >= i:
			break
		Pn1 = j
		Pn2 = i - j

		# if Pn2 is not a Pn
		tempNum = pentagonNumbersToN(Pn2)
		if (tempNum != int(tempNum)):
			continue

		# tempNum is difference of Pn1 and Pn2
		tempNum = pentagonNumbersToN(abs(Pn1 - Pn2))
		if (tempNum != int(tempNum)):
			continue
		print("%d: %d, %d: %d, %d: %d" % (pentagonNumbersToN(Pn1), Pn1, pentagonNumbersToN(Pn2), Pn2, tempNum, nToPentagonNumbers(tempNum)))
