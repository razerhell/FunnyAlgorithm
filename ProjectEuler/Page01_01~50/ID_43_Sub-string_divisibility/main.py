'''
Sub-string divisibility
Problem 43 
The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

d2d3d4=406 is divisible by 2
d3d4d5=063 is divisible by 3
d4d5d6=635 is divisible by 5
d5d6d7=357 is divisible by 7
d6d7d8=572 is divisible by 11
d7d8d9=728 is divisible by 13
d8d9d10=289 is divisible by 17
Find the sum of all 0 to 9 pandigital numbers with this property.


Answer:
16695334890
Completed on Tue, 26 Dec 2017, 17:44

'''

testList = [2, 3, 5, 7, 11, 13, 17]
baseStuff = set(range(10))
consNum = [-1] * 10
stuffs = [None]

def isPandigitalNumbers(num):
	for iP, value in enumerate(testList, 1):
		i = iP - 1
		res = num % ( 10 ** ( 10 - iP ))
		res /= 10 ** (7 - iP)
		res = int(res)
		if ( res % testList[i] != 0):
			return False
	return True

print(isPandigitalNumbers(1406357289))

def listToNum(l):
	res = 0
	for i in l:
		res *= 10
		res += i
	return res

def constractNum(numCons, n):
	if n > 9:
		nn = listToNum(numCons)
		if not isPandigitalNumbers(nn):
			return
		print(nn)
		stuffs.append(nn)
		return
	numStuffSet = set(numCons)
	stuffSet = baseStuff - numStuffSet
	for i in stuffSet:
		numCons[n] = i
		constractNum(numCons, n + 1)
	numCons[n] = -1

constractNum(consNum, 0)

print("sum: %d" % sum(stuffs))