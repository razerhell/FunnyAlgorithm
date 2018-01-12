'''
Permuted multiples
Problem 52 
It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.


Answer:
142857
Completed on Fri, 12 Jan 2018, 10:37

new Permuted Multiples Number: 125874, times: 2
125874
251748
new Permuted Multiples Number: 142857, times: 6
142857
285714
428571
571428
714285
857142

'''


def numToDigit(num: int):
	if num == 0:
		return [0]
	digits = []
	while not num == 0:
		n = num % 10
		num = int(num / 10)
		digits.append(n)
	return digits

def listToDict(digitL):
	dd = dict()
	for i in digitL:
		if i in dd.keys():
			dd[i] += 1
		else:
			dd[i] = 1
	return dd


def isDictSample(dict1, dict2):
	if len(dict1) != len(dict2):
		return False

	for k, v in dict1.items():
		if dict2.get(k, -1) == v:
			continue
		return False

	return True

def findNum(bot, top):
	maxPermutedTime = 1
	for i in range(bot, top):
		tempI = i
		iPermutedTime = 1
		idd = listToDict(numToDigit(tempI))
		tempI += i
		while (isDictSample(idd, listToDict(numToDigit(tempI)))):
			tempI += i
			iPermutedTime += 1
		if iPermutedTime <= maxPermutedTime:
			continue

		print("new Permuted Multiples Number: %d, times: %d" % (i, iPermutedTime))
		maxPermutedTime = iPermutedTime
		tempI = i
		for j in range(0, iPermutedTime):
			print(tempI)
			tempI += i


MAX_POWER = 7
MAX_NUM = 10 ** MAX_POWER
MIN_NUM = 10 ** (MAX_POWER - 1)
for i in range(1, 11):
	MAX_POWER = i
	MAX_NUM = 10 ** MAX_POWER
	MIN_NUM = 10 ** (MAX_POWER - 1)
	findNum (MIN_NUM, MAX_NUM)