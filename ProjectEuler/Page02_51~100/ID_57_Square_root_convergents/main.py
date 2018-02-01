'''

Square root convergents
Problem 57 
It is possible to show that the square root of two can be expressed as an infinite continued fraction.

√ 2 = 1 + 1/(2 + 1/(2 + 1/(2 + ... ))) = 1.414213...

By expanding this for the first four iterations, we get:

1 + 1/2 = 3/2 = 1.5
1 + 1/(2 + 1/2) = 7/5 = 1.4
1 + 1/(2 + 1/(2 + 1/2)) = 17/12 = 1.41666...
1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 = 1.41379...

The next three expansions are 99/70, 239/169, and 577/408, but the eighth expansion, 1393/985, is the first example where the number of digits in the numerator exceeds the number of digits in the denominator.

In the first one-thousand expansions, how many fractions contain a numerator with more digits than denominator?


Answer:
153
Completed on Sun, 28 Jan 2018, 18:50

'''

def getNext(t:tuple):
	x = t[1]
	y = t[0]
	return (x, x + x + y)

def countDigit(num : int):
	return len(list(str(num)))

t = (1, 2)



expansionsTime = 1000
overCount = 0

for i in range(expansionsTime):
	t = getNext(t)
	tempNumerator = t[0] + t[1]
	tempDenominator = t[1]
	numDigit = countDigit(tempNumerator)
	denDigit = countDigit(tempDenominator)
	if numDigit <= denDigit:
		continue

	overCount += 1
	print("%d, %d : %d, %d" % (tempNumerator, tempDenominator, numDigit, denDigit))
print("count:")
print(overCount)