'''

Lychrel numbers
Problem 55 
If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

Not all numbers produce palindromes so quickly. For example,

349 + 943 = 1292,
1292 + 2921 = 4213
4213 + 3124 = 7337

That is, 349 took three iterations to arrive at a palindrome.

Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. A number that never forms a palindrome through the reverse and add process is called a Lychrel number. Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise. In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome. In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).

Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.

How many Lychrel numbers are there below ten-thousand?

NOTE: Wording was modified slightly on 24 April 2007 to emphasise the theoretical nature of Lychrel numbers.

Answer:
249
Completed on Fri, 26 Jan 2018, 14:49


'''


def numberToList(num):
	res = list()
	if (num == 0):
		return [0]

	while num != 0:
		n = num % 10
		res.append(n)
		num = int(num / 10)
	return res

def listToNumber(digits):
	res = 0
	for i in digits[::-1]:
		res *= 10
		res += i

	return res

def isPalindromic(digits):
	n = int(len(digits) / 2)
	for i in range(n):
		if digits[i] == digits[-(i + 1)]:
			continue
		return False
	return True

def getLychrelNumbers(num, numList, iteraMax):
	numList.clear()
	while iteraMax != 0:
		iteraMax -= 1
		numList.append(num)
		numd = numberToList(num)
		num += listToNumber(numd[::-1])

		if (isPalindromic(numberToList(num))):
			return False
	return True

MAX_NUMBER = 10000
nums = list()
NUMBER_RES = [-1] * (MAX_NUMBER + 1)

for i in range(MAX_NUMBER + 1):
	if NUMBER_RES[i] != -1:
		continue

	res = getLychrelNumbers(i, nums, 50)
	
	if res :
		res = 0
	else:
		res = 1

	for j in nums:
		if j > MAX_NUMBER:
			break
		NUMBER_RES[j] = res

countLychrelNumbers = 0

for i in range(MAX_NUMBER + 1):
	if NUMBER_RES[i] == 1:
		continue
	countLychrelNumbers += 1

print(countLychrelNumbers)