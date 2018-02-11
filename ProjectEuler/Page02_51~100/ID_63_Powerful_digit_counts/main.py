'''
Powerful digit counts
Problem 63 
The 5-digit number, 16807=75, is also a fifth power. Similarly, the 9-digit number, 134217728=89, is a ninth power.

How many n-digit positive integers exist which are also an nth power?


Answer:
49
Completed on Sun, 11 Feb 2018, 08:20

'''

def getNumLenth(num:int):
	return len(str(num))

numCount = 0
for i in range(1, 10):
	j = 0
	currCount = 0
	while True:
		jbk = j
		j += 1
		power = i ** jbk
		powerLen = getNumLenth(power)
		if abs(powerLen - jbk) > 3:
			break

		if powerLen == jbk:
			numCount += 1
			currCount += 1
		print("base: %d, power: %d" % (i, jbk), end = '\t')
		print("%d" % (getNumLenth(power), ))
	print(currCount)
	print()

print(numCount)

