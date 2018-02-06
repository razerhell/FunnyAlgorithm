'''
Spiral primes
Problem 58 
Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.

37 36 35 34 33 32 31
38 17 16 15 14 13 30
39 18  5  4  3 12 29
40 19  6  1  2 11 28
41 20  7  8  9 10 27
42 21 22 23 24 25 26
43 44 45 46 47 48 49

It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13 ≈ 62%.

If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed. If this process is continued, what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?


Answer:
26241
Completed on Tue, 6 Feb 2018, 08:18

'''

def getNext4Vertex(layer:int, currNum:int):
	res = list()
	step = layer - 1
	for i in range(4):
		currNum += step
		res.append(currNum)
	return res

from math import sqrt

def isPrime(num:int):
	maxL = int(sqrt(num)) + 1
	for i in range(2, maxL):
		if num % i == 0:
			return False
	return True

MAX_LAYER = 7
CURR_LAYER = 1
CURR_NUM = 1
STEP_COUNT = 1
PRIME_COUNT = 0

while (True):
	CURR_LAYER += 2
	res = getNext4Vertex(CURR_LAYER, CURR_NUM)
	CURR_NUM = res[3]
	pris = list()
	nonpris = list()
	for i in res:
		if isPrime(i):
			pris.append(i)
		else :
			nonpris.append(i)

	STEP_COUNT += 4
	PRIME_COUNT += len(pris)

	ratio = PRIME_COUNT / STEP_COUNT  * 100

	print("side length: %d\t\t" % (CURR_LAYER), end = '')
	print(res)
	print("primes:", end='')
	print(pris)
	print("non-primes", end='')
	print(nonpris)
	print(ratio, end = '')
	print("%")
	print()
	if (ratio < 10):
		break